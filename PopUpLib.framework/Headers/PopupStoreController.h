//
//  PopupStoreController.h
//  PopUpLib
//
//  Created by CanvasPop on 11/1/2013.
//  Copyright (c) 2018 CanvasPop. All rights reserved.
//

@import UIKit;

@protocol PopupStoreControllerDelegate;

///--------------------------------------------------
/// @name Public Interface
///--------------------------------------------------
#pragma mark - Public Interface

@interface PopupStoreController : UIViewController <UIWebViewDelegate,NSURLSessionDelegate>

/**
 *  Your CanvasPop Partner API key.
 *  For more information, visit https://developers.canvaspop.com
 */
@property (copy, nonatomic) NSString *applicationKey;

/**
 *  Should we display or hide the status bar?
 *  `YES` to display the status bar, `NO` otherwise.
 */
@property (assign, nonatomic) BOOL shouldDisplayStatusBar;

/**
 *  An object acting as our controller's delegate.
 *  Multiple actions will be forwarded to the delegate in order to react to certain actions.
 */
@property (weak, nonatomic) id<PopupStoreControllerDelegate> storeDelegate;

/**
 *  This is the image we will be processing through the store.
 */
@property (strong, nonatomic) UIImage *storeImage;

/**
 *  Instantiates a view controller with an image, your CanvasPop Partner API key and a delegate.
 *
 *  @param image     The image to process through the store.
 *  @param appKey    Your CanvasPop Partner API key
 *  @param aDelegate An object acting as our controller's delegate.
 *
 *  @return An instance of our view controller class.
 */
- (instancetype)initWithImage:(UIImage *)image applicationKey:(NSString *)appKey delegate:(id<PopupStoreControllerDelegate>)aDelegate;

@end

///--------------------------------------------------
/// @name Delegate Protocol
///--------------------------------------------------
#pragma mark - Delegate Protocol

@protocol PopupStoreControllerDelegate <NSObject>

@required

/**
 *  This delegate method is required.
 *  This method will be called when the user has closed the store.
 *
 *  @param controller The controller receiving the 'close' intention by the user.
 */
- (void)popupStoreLibWasClosed:(PopupStoreController *)controller;

@optional

/**
 *  This delegate method is optional.
 *  Use this delegate method to react to events emitted by the controller.
 *  An event will be emitted when the user completes a purchase.
 *  For more info, see https://developers.canvaspop.com/documentation/features
 *
 *  @param controller The controller emitting the event.
 *  @param eventName  The event emitted by the controller.
 *  @param payload    The payload attached to the event.
 */
- (void)popupStoreEventWasEmitted:(PopupStoreController *)controller withEvent:(NSString*)eventName withPayload:(NSDictionary *)payload;

/**
 *  This delegate method is optional.
 *  This method will be called upon completion of the upload of the image.
 *
 *  @param controller The controller uploading the image.
 */
- (void)popupStoreLibPrintHandshakeCompleted:(PopupStoreController *)controller;

/**
 *  This delegate method is optional.
 *  This method is called when the user has tapped 'continue'.
 *
 *  @param controller The controller receiving the 'continue' intention by the user.
 */
- (void)popupStoreLibUserTappedContinue:(PopupStoreController *)controller;

/**
 *  This delegate method is optional.
 *  This method will be called once the store has been opened successfully.
 *
 *  @param controller The controller opening the store.
 */
- (void)popupStoreLibWasOpened:(PopupStoreController *)controller;

/**
 *  This delegate method is optional.
 *  This method will be called when the store has loaded successfully.
 *
 *  @param controller The controller loading the store.
 */
- (void)popupStoreWasLoadedWithImage:(PopupStoreController *)controller;

@end
