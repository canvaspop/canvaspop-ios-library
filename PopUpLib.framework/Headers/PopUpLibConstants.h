//
//  PopUpLibConstants.h
//  PopUpLib
//
//  Created by CanvasPop on 10/30/2013.
//  Copyright (c) 2018 CanvasPop. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PopUpLibConstants : NSObject

extern NSString *const CP_API_PREVIEW_ENDPOINT;
extern NSString *const CP_API_PRINT_ENDPOINT;
extern NSString *const CP_MERCHANDISING_BASE_URL;
extern NSString *const CP_MERCHANDISING_CONTINUE_URL;
extern NSString *const CP_ERROR_HANDLING_URL;
extern NSString *const CP_CART_BASE_URL;
extern NSString *const CP_LOADER_BASE_URL;
extern NSString *const CP_API_AUTH_TYPE_HEADER;
extern NSString *const CP_API_AUTH_TYPE_VALUE;
extern NSString *const CP_API_AUTH_KEY_HEADER;
extern NSString *const CP_IMAGE_PREVIEW_FILENAME;
extern NSString *const CP_IMAGE_PRINT_FILENAME;
extern NSString *const CP_BUNDLE_NAME;
extern NSString *const CP_CONTINUE_BUTTON_TEXT;
extern NSString *const CP_PREVIEW_HANDSHAKE_ERROR;
extern NSString *const CP_PRINT_HANDSHAKE_ERROR;
extern NSString *const CP_TOKEN_PARAM_NAME;
extern NSString *const CP_JSON_TOKEN_PARAM_NAME;
extern NSString *const CP_ERROR_ALERT_TITLE;
extern NSString *const CP_ERROR_CANCEL_TITLE;
extern NSString *const CP_JPEG_CONTENT_TYPE;
extern NSString *const CP_IMAGE_HANDSHAKE_FORM_KEY;

extern float const CP_IMAGE_PREVIEW_MAX_WIDTH;
extern float const CP_IMAGE_PREVIEW_MAX_HEIGHT;
extern float const CP_DEFAULT_DPI;
extern float const CP_DEFAULT_REQUEST_TIMEOUT;
extern float const HTTP_STATUS_CODE_OK;
extern float const HANDSHAKE_REQUEST_CODE_CANCELLED;

extern bool const CP_DEFAULT_SHOULD_SHOW_STATUS_BAR;

//Error Codes
extern float const CP_PREVIEW_GENERATION_FAILURE_CODE;
extern float const CP_JSON_PARSE_FAILURE_CODE;
extern float const CP_PREVIEW_HANDSHAKE_EXCEPTION_CODE;
extern float const CP_PRINT_HANDSHAKE_EXCEPTION_CODE;

@end
