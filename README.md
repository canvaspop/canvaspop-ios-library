canvaspop-ios-library
=====================

The CanvasPop iOS Library makes it easy to integrate Pop-up Store into your application.

![lib-screenshot](https://cp-static.s3.amazonaws.com/popupstore/documentation/lib-screenshot.png)

**Current version:** 1.0.2 [(download)](https://github.com/canvaspop/canvaspop-ios-library/archive/master.zip)

## Installation

Installing PopUpLibLib.framework is simple.

1. [Download the repo](https://github.com/canvaspop/canvaspop-ios-library/archive/master.zip) from github

2. Drag `PopUpLib.bundle` and `PopUpLib.framework` into your project.
    
    ![lib-copy](https://cp-static.s3.amazonaws.com/popupstore/documentation/lib1.png)


3. In the Build Phases tab of your app's Target, under the "Link Binary With Libraries" section, hit the add button and add: **MobileCoreServices.framework**, **CFNetwork.framework**, **SystemConfiguration.framework**, **libz.dylib**

    ![lib-dep1](https://cp-static.s3.amazonaws.com/popupstore/documentation/lib2.png)
    ![lib-dep1](https://cp-static.s3.amazonaws.com/popupstore/documentation/lib3.png)
    ![lib-dep1](https://cp-static.s3.amazonaws.com/popupstore/documentation/lib4.png)
    ![lib-dep1](https://cp-static.s3.amazonaws.com/popupstore/documentation/lib5.png)

    
If you encounter any issues, please feel free to report them here: https://github.com/canvaspop/canvaspop-ios-library/issues

## Integration

Integrating the CanvasPop iOS library into your app is very simple.

There are two main files included with the framework.

| File          | Description   |
| :------------ | :------------ |
|**PopUpLib.h**| The file you include in your project i.e. `#import <PopUpLib/PopUpLib.h>` |
|**PopUpStoreController.h**| The view controller you will need to initiate and present |

1. Choose where your users will launch the Pop-up Store Controller. Inside the header file for your controller, add `#import <PopUp/PopUpLib.h>` and implement the `PopupStoreControllerDelegate` protocol:
    ````objective-c
    @interface ViewController : UIViewController <PopupStoreControllerDelegate> {
    }
    ````
2. At the desired time (e.g. tapping a button, after taking/editing a photo), instantiate a PopupStoreController. If one was created successfully (i.e. the call did not return `nil`), present the Pop-up Store controller.

    **Parameters**
    - `image` - the image that will be printed on canvas
    - `applicationKey` - your partner API key 
    - `delegate` -  Any class that implements the PopupStoreControllerDelegate protocol (usually self)
    
    ````objective-c
    PopupStoreController *controller =  [[PopupStoreController alloc] 
                                        initWithImage:[UIImage imageNamed:@"your_descired_image.jpg"] 
                                        applicationKey:YOUR_PARTNER_KEY 
                                        delegate:self];
                                                                     
    if (controller) {
        [self presentViewController:controller animated:YES completion:NULL];
    }
    ````
3. Implement the `PopupStoreControllerDelegate` protocol. There are currently six delegate methods; one that is required and five that may be optionally implemented. They are as follows:
    
    **Required**

    ````objective-c
    - (void)popupStoreLibWasClosed:(PopupStoreController *)lib
    {
        /*
        * Here a user has closed the Pop-up Store controller and it must be dismissed
        */
        [self dismissViewControllerAnimated:YES completion:nil];
    }
    ````

    **Optional**
    
    The following methods are optional and may be implemented to receive callbacks.

    ````objective-c
    - (void)popupStoreLibWasOpened:(PopupStoreController *)lib
    {
        /*
        * Here a user has opened the Pop-up Store controller successfully
        */
        NSLog(@"Pop-up Store lib was opened");
    }

    - (void)popupStoreLibUserTappedContinue:(PopupStoreController *)lib
    {
        /*
        * Here a user has tapped the continue button after the initial image handshake was completed
        * The user will then be taken to the store with their desired image
        */
        NSLog(@"Pop-up Store user tapped continue");
    }

    - (void)popupStoreWasLoadedWithImage:(PopupStoreController *)lib
    {
        /*
        * Here the web request to load Pop-up Store with a users image completed successfully
        * A user is presented with a cart containing their image and print options
        */
        NSLog(@"Pop-up Store cart page loaded successfully with image");
    }

    - (void)popupStoreLibPrintHandshakeCompleted:(PopupStoreController *)lib
    {
        /*
        * The library implements a two-step handshake documented here: https://developers.canvaspop.com/documentation/image-handshake#two-step
        * Here the high resolution, printable version of the desired image was uploaded succesfully
        * 
        */
        NSLog(@"Pop-up Store print image handshake completed");
    }
    
    - (void)popupStoreEventWasEmitted:(PopupStoreController *)controller withEvent:(NSString*)eventName withPayload:(NSDictionary *)payload
    {
        /*
        * Here a user has interacted with Pop-up Store and an HTML5 pushMessage() was emitted.
        * Depending on the event, it may have an associated payload value sent along with the event name.
        * 
        * For further details emitted events and their payloads see here: 
        * https://developers.canvaspop.com/documentation/events
        */
        
        NSLog(@"PopupStore event was emitted with payload");
        
        NSLog(@"Event: %@", eventName);
    
        if(payload)
            NSLog(@"Payload: %@", payload);
    }

    ````
    
## Support

We're always happy to help out with code or any other questions you might have. 
It's important to us that you are able to get PopUp Store integrated into your application as quickly and smoothly as possible.

**Email**:   [api.support@canvaspop.com](mailto:api.support@canvaspop.com)

**Twitter**: [CanvasPopApi](https://twitter.com/CanvasPopApi)

Looking for more information on the API itself? Check out [https://developers.canvaspop.com/](https://developers.canvaspop.com/)

## Bugs

Noticed a bug in the library or documentation? 

Please feel free to report any issues here: https://github.com/canvaspop/canvaspop-ios-library/issues

