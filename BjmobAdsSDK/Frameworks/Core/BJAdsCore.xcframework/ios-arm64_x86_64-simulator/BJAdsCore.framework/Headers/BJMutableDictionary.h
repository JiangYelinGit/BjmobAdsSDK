//
//  BJMutableDictionary.h
//  FFFFF
//
//  Created by cc on 2022/4/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BJMutableDictionary : NSObject

/// Returns an object given a key in the dictionary or nil if not found.
- (id)objectForKey:(id)key;

/// Updates the object given its key or adds it to the dictionary if it is not in the dictionary.
- (void)setObject:(id)object forKey:(id<NSCopying>)key;

/// Removes the object given its session ID from the dictionary.
- (void)removeObjectForKey:(id)key;

/// Removes all objects.
- (void)removeAllObjects;

/// Returns the number of current objects in the dictionary.
- (NSUInteger)count;

/// Returns an object given a key in the dictionary or nil if not found.
- (id)objectForKeyedSubscript:(id<NSCopying>)key;

/// Updates the object given its key or adds it to the dictionary if it is not in the dictionary.
- (void)setObject:(id)obj forKeyedSubscript:(id<NSCopying>)key;

/// Returns the immutable dictionary.
- (NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
