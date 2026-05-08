
#import <Foundation/Foundation.h>
#import <ThingAnnotationFoundation/ThingAnnotationFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingModuleLinkedItem : NSObject

@property (nonatomic, strong) NSNumber *priority;
@property (nonatomic, strong) ThingModuleLinkedItem *next;
@property (nonatomic, weak) id module;

@property (nonatomic, weak) Class vc;

/**
 * Inserts an item into a linked list, sorted by priority.
 *
 * This method ensures that the linked list remains sorted with the highest priority nodes first.
 *
 * @param item The item to insert into the linked list.
 * @param head The head of the existing linked list.
 * @return The new head of the linked list.
 */
+ (ThingModuleLinkedItem *)insertItem:(ThingModuleLinkedItem *)item toLinked:(ThingModuleLinkedItem *)head;

/**
 * Cleans the linked list by removing nodes whose modules have been deallocated.
 *
 * This method traverses the linked list, removing any nodes that reference deallocated modules.
 *
 * @param head The head of the linked list to clean.
 * @return The new head of the linked list after cleaning.
 */
+ (ThingModuleLinkedItem *)cleanNilInLinked:(ThingModuleLinkedItem *)head;

@end

NS_ASSUME_NONNULL_END
