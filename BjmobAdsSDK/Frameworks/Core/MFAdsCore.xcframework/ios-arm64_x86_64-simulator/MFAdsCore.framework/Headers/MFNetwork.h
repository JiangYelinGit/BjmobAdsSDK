//
//  MFNetwork.h
//  NetWorkDemo
//
//  Created by cc on 2022/4/22.
//

#import <Foundation/Foundation.h>
#import "MFNetworkConstants.h"
#import "MFNetworkLoggerProtocol.h"
#import "MFNetworkURLSession.h"

NS_ASSUME_NONNULL_BEGIN

/// Delegate protocol for MFNetwork events.
@protocol MFNetworkReachabilityDelegate

/// Tells the delegate to handle events when the network reachability changes to connected or not
/// connected.
- (void)reachabilityDidChange;

@end

@interface MFNetwork : NSObject

/// Indicates if network connectivity is available.
@property(nonatomic, readonly, getter=isNetworkConnected) BOOL networkConnected;

/// Indicates if there are any uploads in progress.
@property(nonatomic, readonly, getter=hasUploadInProgress) BOOL uploadInProgress;

/// An optional delegate that can be used in the event when network reachability changes.
@property(nonatomic, weak) id<MFNetworkReachabilityDelegate> reachabilityDelegate;

/// An optional delegate that can be used to log messages, warnings or errors that occur in the
/// network operations.
@property(nonatomic, weak) id<MFNetworkLoggerProtocol> loggerDelegate;

/// Indicates whether the logger should display debug messages.
@property(nonatomic, assign) BOOL isDebugModeEnabled;

/// The time interval in seconds for the network request to timeout.
@property(nonatomic, assign) NSTimeInterval timeoutInterval;

/// Initializes with the default reachability host.
- (instancetype)init;

/// Initializes with a custom reachability host.
- (instancetype)initWithReachabilityHost:(NSString *)reachabilityHost;

/// Handles events when background session with the given ID has finished.
+ (void)handleEventsForBackgroundURLSessionID:(NSString *)sessionID
                            completionHandler:(MFNetworkSystemCompletionHandler)completionHandler;

/// Compresses and sends a POST request with the provided data to the URL. The session will be
/// background session if usingBackgroundSession is YES. Otherwise, the POST session is default
/// session. Returns a session ID or nil if an error occurs.
- (NSString *)postURL:(NSURL *)url
                   payload:(NSData *)payload
                     queue:(dispatch_queue_t)queue
    usingBackgroundSession:(BOOL)usingBackgroundSession
         completionHandler:(MFNetworkCompletionHandler)handler;

/// Sends a GET request with the provided data to the URL. The session will be background session
/// if usingBackgroundSession is YES. Otherwise, the GET session is default session. Returns a
/// session ID or nil if an error occurs.
- (NSString *)getURL:(NSURL *)url
                   headers:(NSDictionary *)headers
                     queue:(dispatch_queue_t)queue
    usingBackgroundSession:(BOOL)usingBackgroundSession
         completionHandler:(MFNetworkCompletionHandler)handler;

- (void)downloadFileWihtPath:(NSString *)path
                    savePath:(NSString *)savePath
      usingBackgroundSession:(BOOL)usingBackgroundSession
           completionHandler:(MFNetworkCompletionHandler)handler;


@end

NS_ASSUME_NONNULL_END
