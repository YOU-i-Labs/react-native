/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * @flow
 * @format
 */

'use strict';

import type {TurboModule} from 'RCTExport';
import * as TurboModuleRegistry from 'TurboModuleRegistry';

export interface Spec extends TurboModule {
  +getConstants: () => {|
    initialAppState: string,
  |};
  +getCurrentAppState: (
    success: (appState: {|app_state: string|}) => void,
    failure: (error: Object) => void,
  ) => void;

  // Events
  +addListener: (eventName: string) => void;
  +removeListeners: (count: number) => void;
}

export default TurboModuleRegistry.getEnforcing<Spec>('AppState');
