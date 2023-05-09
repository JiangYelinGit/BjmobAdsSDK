/*
 * Copyright 2017 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>
#if !TARGET_OS_WATCH
#import <SystemConfiguration/SystemConfiguration.h>
#endif

/// Reachability Status
typedef enum {
  kMFReachabilityUnknown,  ///< Have not yet checked or been notified whether host is reachable.
  kMFReachabilityNotReachable,  ///< Host is not reachable.
  kMFReachabilityViaWifi,       ///< Host is reachable via Wifi.
  kMFReachabilityViaCellular,   ///< Host is reachable via cellular.
} MFReachabilityStatus;

const NSString *MFReachabilityStatusString(MFReachabilityStatus status);

@class MFReachabilityChecker;

/// Google Analytics iOS Reachability Checker.
@protocol MFReachabilityDelegate
@required
/// Called when network status has changed.
- (void)reachability:(MFReachabilityChecker *)reachability
       statusChanged:(MFReachabilityStatus)status;
@end

/// Google Analytics iOS Network Status Checker.
@interface MFReachabilityChecker : NSObject

/// The last known reachability status, or MFReachabilityStatusUnknown if the
/// checker is not active.
@property(nonatomic, readonly) MFReachabilityStatus reachabilityStatus;
/// The host to which reachability status is to be checked.
@property(nonatomic, copy, readonly) NSString *host;
/// The delegate to be notified of reachability status changes.
@property(nonatomic, weak) id<MFReachabilityDelegate> reachabilityDelegate;
/// `YES` if the reachability checker is active, `NO` otherwise.
@property(nonatomic, readonly) BOOL isActive;

/// Initialize the reachability checker. Note that you must call start to begin checking for and
/// receiving notifications about network status changes.
///
/// @param reachabilityDelegate The delegate to be notified when reachability status to host
/// changes.
///
/// @param host The name of the host.
///
- (instancetype)initWithReachabilityDelegate:(id<MFReachabilityDelegate>)reachabilityDelegate
                                    withHost:(NSString *)host;

- (instancetype)init NS_UNAVAILABLE;

/// Start checking for reachability to the specified host. This has no effect if the status
/// checker is already checking for connectivity.
///
/// @return `YES` if initiating status checking was successful or the status checking has already
/// been initiated, `NO` otherwise.
- (BOOL)start;

/// Stop checking for reachability to the specified host. This has no effect if the status
/// checker is not checking for connectivity.
- (void)stop;

@end
