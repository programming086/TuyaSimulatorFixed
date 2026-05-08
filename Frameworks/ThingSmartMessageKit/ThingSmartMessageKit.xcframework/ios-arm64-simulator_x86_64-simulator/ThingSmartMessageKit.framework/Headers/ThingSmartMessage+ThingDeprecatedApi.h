
#import "ThingSmartMessage.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartMessage (ThingDeprecatedApi)


/// Get the message list.
///
/// @param msgType      Message type
/// @param limit        Limit
/// @param offset       Offset  start from zero
/// @param success      Success block
/// @param failure      Failure block
/// @deprecated This method is deprecated, Use ThingSmartMessage::fetchMessageListWithListRequestModel:success:failure: instead.
- (void)getMessageListWithType:(ThingMessageType)msgType limit:(NSInteger)limit offset:(NSInteger)offset success:(void (^)(NSArray<ThingSmartMessageListModel *> *list))success failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use -[ThingSmartMessage fetchMessageListWithListRequestModel:success:failure:] instead");


/// Get the message list by message type.
///
/// @param msgType      Message type
/// @param msgSrcId     Detail message Id
/// @param limit        Limit
/// @param offset       Offset  start from zero
/// @param success      Success block
/// @param failure      Failure block
/// @deprecated This method is deprecated, Use ThingSmartMessage::fetchMessageDetailListWithListRequestModel:success:failure: instead.
- (void)getMessageDetailListWithType:(NSInteger)msgType msgSrcId:(NSString *)msgSrcId limit:(NSInteger)limit offset:(NSInteger)offset success:(void (^)(NSArray<ThingSmartMessageListModel *> *list))success failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use -[ThingSmartMessage fetchMessageDetailListWithListRequestModel:success:failure:] instead");


/// Get the message list.
///
/// @param success      Success block
/// @param failure      Failure block
/// @deprecated This method is deprecated, Use ThingSmartMessage::getMessageListWithType:limit:offset:success:failure: or ThingSmartMessage::getMessageDetailListWithType:msgSrcId:limit:offset:success:failure: instead.
- (void)getMessageList:(void (^)(NSArray<ThingSmartMessageListModel *> *list))success
               failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use -[ThingSmartMessage getMessageListWithType:limit:offset:success:failure:] or -[ThingSmartMessage getMessageDetailListWithType:msgSrcId:limit:offset:success:failure:] instead");



/// Get next page message list.
///
/// @param limit        Limit
/// @param offset       Offset  start from zero
/// @param success      Success block
/// @param failure      Failure block
/// @deprecated This method is deprecated, Use ThingSmartMessage::getMessageListWithType:limit:offset:success:failure: or ThingSmartMessage::getMessageDetailListWithType:msgSrcId:limit:offset:success:failure: instead.
- (void)getMessageList:(NSInteger)limit
                offset:(NSInteger)offset
               success:(void (^)(NSArray<ThingSmartMessageListModel *> *list))success
               failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use -[ThingSmartMessage getMessageListWithType:limit:offset:success:failure:] or -[ThingSmartMessage getMessageDetailListWithType:msgSrcId:limit:offset:success:failure:] instead");



/// Deletes a batch of messages
///
/// @param messgeIdList Message Id list
/// @param success      Success block
/// @param failure      Failure block
/// @deprecated This method is deprecated, Use ThingSmartMessage::deleteMessageWithType:ids:msgSrcIds:success:failure: instead.
- (void)deleteMessage:(NSArray <NSString *> *)messgeIdList
              success:(ThingSuccessHandler)success
              failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use -[ThingSmartMessage deleteMessageWithType:ids:msgSrcIds:success:failure:] instead");



/// Get the timestamp of the newest message
///
/// @param success      Success block
/// @param failure      Failure block
/// @deprecated This method is deprecated, Use ThingSmartMessage::getLatestMessageWithSuccess:failure: instead.
- (void)getMessageMaxTime:(ThingSuccessInt)success
                  failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use -[ThingSmartMessage getLatestMessageWithSuccess:failure:] instead");


/// Delete a batch of messages
///
/// @param msgType      Message type
/// @param ids          Delete message Id list
/// @param msgSrcIds    Delete alert message Id list
/// @param success      Success block
/// @param failure      Failure block
/// @deprecated This method is deprecated, Use ThingSmartMessage::deleteMessageWithDeleteRequestModel:failure: instead.
- (void)deleteMessageWithType:(NSInteger)msgType ids:(NSArray *)ids msgSrcIds:(NSArray *)msgSrcIds success:(ThingSuccessHandler)success failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use -[ThingSmartMessage deleteMessageWithDeleteRequestModel:failure:] instead");

@end

NS_ASSUME_NONNULL_END
