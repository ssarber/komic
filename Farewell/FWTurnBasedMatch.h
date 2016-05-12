//
//  FWTurnBasedMatch.h
//  Farewell
//
//  Created by Zook Gek on 5/3/16.
//  Copyright © 2016 Stan Sarber. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GameKit/GameKit.h>

@protocol FWTurnBasedMatchDelegate <NSObject>
- (void)enterNewGame:(GKTurnBasedMatch *)match;
- (void)layoutMatch:(GKTurnBasedMatch *)match;
- (void)takeTurnInGame:(GKTurnBasedMatch *)match;
- (void)receiveEndGame:(GKTurnBasedMatch *)match;
- (void)sendNotice:(NSString *)notice forMatch:(GKTurnBasedMatch *)match;
@end

@interface FWTurnBasedMatch : NSObject <GKLocalPlayerListener, GKTurnBasedMatchmakerViewControllerDelegate>

@property (nonatomic, assign) BOOL userAuthenticated;

@property (nonatomic, strong) UIViewController *presentingViewController;

@property (nonatomic, strong) GKTurnBasedMatch *currentMatch;

@property (nonatomic, weak) id <FWTurnBasedMatchDelegate> delegate;

+ (FWTurnBasedMatch *)sharedInstance;

- (void)authenticateLocalUserFromController:(UIViewController *)controller;

- (void)findMatchWithMinPlayers:(NSUInteger)minPlayers
                     maxPlayers:(NSUInteger)maxPlayers
             showExistingMatches:(BOOL)show
                 viewController:(UIViewController *)viewController;

@end
