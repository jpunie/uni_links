#import <Flutter/Flutter.h>
#import <CoreNFC/CoreNFC.h>

NS_ASSUME_NONNULL_BEGIN

@protocol UriDelegate <NSObject>
- (void) foundUri:(NSString* _Nullable) uri;
@end

@interface UniLinksPlugin : NSObject <FlutterPlugin>
+ (instancetype)sharedInstance;
- (BOOL)application:(UIApplication *)application
    continueUserActivity:(NSUserActivity *)userActivity
      restorationHandler:(void (^)(NSArray *_Nullable))restorationHandler;
@end

API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(macos, watchos, tvos)
@interface NFCCallbacks : NSObject <NFCNDEFReaderSessionDelegate>
@property(nonatomic, weak) _Nullable id <UriDelegate> delegate;
@property(nonatomic, copy) NSString* _Nullable dialogMessage;
@property(nonatomic, strong) NFCNDEFReaderSession * _Nullable nfcReaderSession;
- (void) start;
- (void) stop;
@end

NS_ASSUME_NONNULL_END
