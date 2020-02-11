/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the LICENSE
 * file in the root directory of this source tree.
 */
#pragma once
#include "YGFloatOptional.h"
#include "Yoga-internal.h"

#if defined(_MSC_VER)
#define ENUM_BITFIELDS_NOT_SUPPORTED
#endif

#if !defined(ENUM_BITFIELDS_NOT_SUPPORTED)
#define BITFIELD_ENUM_SIZED(num) : num
#else
#define BITFIELD_ENUM_SIZED(num)
#endif

constexpr std::array<float, 2> kYGDefaultDimensionValues = {
    {YGUndefined, YGUndefined}};

struct YGLayout {
  std::array<float, 4> position = {};
  std::array<float, 2> dimensions = kYGDefaultDimensionValues;
  std::array<float, 4> margin = {};
  std::array<float, 4> border = {};
  std::array<float, 4> padding = {};
  YGDirection direction BITFIELD_ENUM_SIZED(2);
  bool didUseLegacyFlag BITFIELD_ENUM_SIZED(1);
  bool doesLegacyStretchFlagAffectsLayout BITFIELD_ENUM_SIZED(1);
  bool hadOverflow BITFIELD_ENUM_SIZED(1);

  uint32_t computedFlexBasisGeneration = 0;
  YGFloatOptional computedFlexBasis = {};

  // Instead of recomputing the entire layout every single time, we cache some
  // information to break early when nothing changed
  uint32_t generationCount = 0;
  YGDirection lastOwnerDirection = (YGDirection) -1;

  uint32_t nextCachedMeasurementsIndex = 0;
  std::array<YGCachedMeasurement, YG_MAX_CACHED_RESULT_COUNT>
      cachedMeasurements = {};
  std::array<float, 2> measuredDimensions = kYGDefaultDimensionValues;

  YGCachedMeasurement cachedLayout = YGCachedMeasurement();

  YGLayout()
      : direction(YGDirectionInherit),
        didUseLegacyFlag(false),
        doesLegacyStretchFlagAffectsLayout(false),
        hadOverflow(false) {}

  bool operator==(YGLayout layout) const;
  bool operator!=(YGLayout layout) const { return !(*this == layout); }
};
