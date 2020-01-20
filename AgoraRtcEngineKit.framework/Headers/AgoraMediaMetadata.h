//
// AgoraMediaMetadata.h
// AgoraRtcEngineKit
//
// Copyright (c) 2018 Agora. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, AgoraMetadataType) {
    AgoraMetadataTypeUnknown = -1,
    AgoraMetadataTypeVideo   = 0,
};

@protocol AgoraMediaMetadataDataSource <NSObject>
@required

/** Retrieves the max metadata size User want to use.
 Call this method when AgoraMediaMetadataDataSource set to engine successfully.
 @return return metadata max size.
 */
- (NSInteger)metadataMaxSize;

/** Occurs when user can send a metadata.
 User should never block the thread in this callback.
 @param timestamp The time stamp of the frame followed the matadata.
 @return the data user want to send.
 */
- (NSData * _Nullable)readyToSendMetadataAtTimestamp:(NSTimeInterval)timestamp;

@end

@protocol AgoraMediaMetadataDelegate <NSObject>
@required

/** Occurs when a metadata received.
 User should never block the thread in this callback.
 @param data The content of the metadata.
 @param uid The user id of the received metadata.
 @param timestamp The timeStamp of the frame that followed the metadata.
 */
- (void)receiveMetadata:(NSData * _Nonnull)data fromUser:(NSInteger)uid atTimestamp:(NSTimeInterval)timestamp;

@end

