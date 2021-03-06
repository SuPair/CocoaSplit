//
//  CSTransitionBase.h
//  CocoaSplit
//
//  Created by Zakk on 3/16/18.
//

#import <Foundation/Foundation.h>
#import <JavascriptCore/JavascriptCore.h>
#import "SourceLayout.h"
#import "CSLayoutTransitionViewProtocol.h"


@protocol CSTransitionExport <JSExport>
@property (strong) NSNumber *duration;
@property (strong) NSString *name;
@property (strong) NSString *subType;
@property (assign) bool active;
@property (strong) NSString *uuid;
@property (strong) CSTransitionBase *preTransition;
@property (strong) CSTransitionBase *postTransition;
@property (assign) bool isToggle;
@property (assign) bool canToggle;

-(NSString *)preChangeAction:(SourceLayout *)targetLayout;
-(NSString *)postChangeAction:(SourceLayout *)targetLayout;
-(NSString *)preReplaceAction:(SourceLayout *)targetLayout;
-(NSString *)postReplaceAction:(SourceLayout *)targetLayout;
-(NSString *)preMergeAction:(SourceLayout *)targetLayout;
-(NSString *)postMergeAction:(SourceLayout *)targetLayout;
-(bool)skipMergeAction:(SourceLayout *)targetLayout;
-(NSString *)preRemoveAction:(SourceLayout *)targetLayout;
-(NSString *)postRemoveAction:(SourceLayout *)targetLayout;

@end

@interface CSTransitionBase : NSObject <CSTransitionExport, NSCopying, NSCoding>
{
    NSString *_name;
}


@property (strong) NSNumber *duration;
@property (strong) NSString *name;
@property (strong) NSString *subType;
@property (assign) bool active;
@property (strong) NSString *uuid;
@property (strong) CSTransitionBase *preTransition;
@property (strong) CSTransitionBase *postTransition;
@property (readonly) bool usesPreTransitions;
@property (readonly) bool usesPostTransitions;
@property (assign) bool isToggle;
@property (assign) bool canToggle;


+(NSArray *)subTypes;
+(NSString *)transitionCategory;

-(NSString *)preChangeAction:(SourceLayout *)targetLayout;
-(NSString *)postChangeAction:(SourceLayout *)targetLayout;
-(NSString *)preReplaceAction:(SourceLayout *)targetLayout;
-(NSString *)postReplaceAction:(SourceLayout *)targetLayout;
-(NSString *)preMergeAction:(SourceLayout *)targetLayout;
-(NSString *)postMergeAction:(SourceLayout *)targetLayout;
-(bool)skipMergeAction:(SourceLayout *)targetLayout;
-(NSString *)preRemoveAction:(SourceLayout *)targetLayout;
-(NSString *)postRemoveAction:(SourceLayout *)targetLayout;

-(NSViewController<CSLayoutTransitionViewProtocol> *)configurationViewController;

@end
