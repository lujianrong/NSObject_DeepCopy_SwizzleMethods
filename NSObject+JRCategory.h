//
//  NSObject+JRCategory.h
//  JRKit
//
//  Created by lujianrong on 16/5/24.
//  Copyright © 2016年 lujianrong. All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@interface NSObject (JRCategory)

+ (NSString *)className;
/**runtime */
-  (NSString *)className;

#pragma mark
#pragma mark - 真正的深拷贝, mutableCopy只会深拷贝一层
/**
 *拷贝自定义类对象需要 先把对象遵循<NSCoding> 不然会抛出异常
 */
- (nullable id)deepCopy;
/**
 *  @param archiver   可传 [NSKeyedArchiver class]
 *  @param unarchiver  可传 [NSKeyedUnarchiver class]
 */
- (nullable id)deepCopyWithArchiver:(Class)archiver unarchiver:(Class)unarchiver;

#pragma mark
#pragma mark - runtime - 交换方法
+ (BOOL)swizzleInstanceMethod:(SEL)originalSel with:(SEL)newSel;
+ (BOOL)swizzleClassMethod:(SEL)originalSel with:(SEL)newSel;
@end

NS_ASSUME_NONNULL_END