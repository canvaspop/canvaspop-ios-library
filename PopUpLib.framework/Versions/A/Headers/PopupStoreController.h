//
//  PopupStoreController.h
//  PopUpLib
//
//  Created by CanvasPop on 11/1/2013.
//  Copyright (c) 2013 CanvasPop. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PopupStoreController;

@protocol PopupStoreControllerDelegate <NSObject>
    @required
    - (void)popupStoreLibWasClosed:(PopupStoreController *)controller;
    @optional
    - (void)popupStoreLibWasOpened:(PopupStoreController *)controller;
    - (void)popupStoreLibPrintHandshakeCompleted:(PopupStoreController *)controller;
    - (void)popupStoreLibUserTappedContinue:(PopupStoreController *)controller;
    - (void)popupStoreWasLoadedWithImage:(PopupStoreController *)controller;
    - (void)popupStoreEventWasEmitted:(PopupStoreController *)controller withEvent:(NSString*)eventName withPayload:(NSDictionary *)payload;
@end

@interface PopupStoreController : UIViewController <UIWebViewDelegate>

-(id)initWithImage:(UIImage *)image applicationKey:(NSString *)appKey delegate:(id <PopupStoreControllerDelegate>)aDelegate;

@property (nonatomic, weak) id <PopupStoreControllerDelegate> storeDelegate;
@property (nonatomic, weak) NSString *applicationKey;
@property (nonatomic, strong) UIImage *storeImage;

@end
