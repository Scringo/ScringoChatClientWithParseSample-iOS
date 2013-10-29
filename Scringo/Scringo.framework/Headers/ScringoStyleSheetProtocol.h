//
//  ScringoStyleSheetProtocol.h
//  ScringoExample3
//
//  Created by Ofer Kalisky on 9/30/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import <Foundation/Foundation.h>

/** List of Scringo screens that are customizable for style sheet customization inmplementations */
typedef NS_ENUM(NSUInteger, ScringoStyleSheetScreenIdentifier) {
    /** Like Button */
    SCRINGO_STYLE_SCREEN_LIKE_BUTTON,
    /** Followers Screen */
    SCRINGO_STYLE_SCREEN_FOLLOWERS,
    /** Panel Screens */
    SCRINGO_STYLE_SCREEN_PANEL,
    /** Inbox Screens */
    SCRINGO_STYLE_SCREEN_INBOX,
    /** Message Compose Screens */
    SCRINGO_STYLE_SCREEN_COMPOSE,
    /** Activity feed Screens */
    SCRINGO_STYLE_SCREEN_ACTIVITY,
    /** Suggested People Screens */
    SCRINGO_STYLE_SCREEN_SUGGESTED_PEOPLE,
    /** Feedback Screens */
    SCRINGO_STYLE_SCREEN_FEEDBACK_MAIN,
    /** Talk to Us Screens */
    SCRINGO_STYLE_SCREEN_FEEDBACK_TALKTOUS,
    /** Find & Invite Friends Screens */
    SCRINGO_STYLE_SCREEN_FIND_INVITE_MAIN,
    /** Find Friends Screens */
    SCRINGO_STYLE_SCREEN_FIND_FRIENDS,
    /** Invite Friends Screens */
    SCRINGO_STYLE_SCREEN_INVITE_FRIENDS,
    /** Suggested Users Screens */
    SCRINGO_STYLE_SCREEN_SUGGESTED_USERS,
    /** Chat Screens */
    SCRINGO_STYLE_SCREEN_CHAT,
    /** Other User Profile Screens */
    SCRINGO_STYLE_SCREEN_OTHER_PROFILE,
    /** Current User Profile Screens */
    SCRINGO_STYLE_SCREEN_MY_PROFILE,
    /** Edit Bio Screen */
    SCRINGO_STYLE_SCREEN_EDIT_BIO,
    /** Radar Annotation Screens */
    SCRINGO_STYLE_SCREEN_RADAR_ANNOTATION,
    /** Radar Screens */
    SCRINGO_STYLE_SCREEN_RADAR,
    /** Full Screen Image Screen */
    SCRINGO_STYLE_SCREEN_FULL_SCREEN_IMAGE,
    /** System Message Screen */
    SCRINGO_STYLE_SCREEN_SYSTEM_MESSAGE,
    /** Chat Rooms Screen */
    SCRINGO_STYLE_SCREEN_CHATROOMS_LIST,
    /** Chat Room Screen */
    SCRINGO_STYLE_SCREEN_CHATROOM,
    /** Leaderboard Screen */
    SCRINGO_STYLE_SCREEN_LEADERBOARD,
    /** Signup Screen */
    SCRINGO_STYLE_SCREEN_SIGNUP,
    /** Login Screen */
    SCRINGO_STYLE_SCREEN_LOGIN,
    /** Email Signup Screen */
    SCRINGO_STYLE_SCREEN_EMAIL_SIGNUP,
    /** Email Login Screen */
    SCRINGO_STYLE_SCREEN_EMAIL_LOGIN,
    /** User Settings Screen */
    SCRINGO_STYLE_SCREEN_USER_SETTINGS,
    /** Quiz Main Screen */
    SCRINGO_STYLE_SCREEN_QUIZ_MAIN,
    /** Quizzes Screen */
    SCRINGO_STYLE_SCREEN_QUIZZES,
    /** Quiz Screen */
    SCRINGO_STYLE_SCREEN_QUIZ,
    /** Quiz Store Screen */
    SCRINGO_STYLE_SCREEN_QUIZ_STORE,
    /** Quiz Suggest Question Screen */
    SCRINGO_STYLE_SCREEN_QUIZ_SUGGEST_QUESTION,
    /** Sticker Pack Screen */
    SCRINGO_STYLE_SCREEN_STICKER_PACK,
    /** Stickers Store Screen */
    SCRINGO_STYLE_SCREEN_STICKER_STORE,
    /** Stickers Keyboard Screen */
    SCRINGO_STYLE_SCREEN_STICKER_KEYBOARD
};

/** Scringo's Style Sheet Protocol Definition.
 
 Allows the application to customize every aspect of Scringo's UI.
 */
@protocol ScringoStyleSheetProtocol <NSObject>

@optional
/**---------------------------------------------------------------------------------------
 * @name General Screen Customization
 *  ---------------------------------------------------------------------------------------
 */

/** Customize Scringo's background image view.
 
 @param backgroundView The image view to customize.
 @param inScreen The screen to customize.
 */
-(void)customizeBackgroundView:(UIImageView *)backgroundView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
/** Customize Scringo's navigation bar background view.
 
 @param navView The navigation bar background view to customize.
 @param inScreen The screen to customize.
 */
-(void)customizeNavbarView:(UIView *)navView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
/** Customize Scringo's navigation bar image view.
 
 @param navImageView The navigation bar image view to customize.
 @param inScreen The screen to customize.
 */
-(void)customizeNavBarImageView:(UIImageView *)navImageView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
/** Customize Scringo's navigation bar title label.
 
 @param screenTitleLabel The navigation bar title label to customize.
 @param inScreen The screen to customize.
 */
-(void)customizeScreenTitleLabel:(UILabel *)screenTitleLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
/** Customize Scringo's navigation bar back button.
 
 @param backButton The navigation bar back button to customize.
 @param inScreen The screen to customize.
 */
-(void)customizeBackButton:(UIButton *)backButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
/** Customize Scringo's navigation bar app button.
 
 @param appButton The navigation bar app button to customize.
 @param inScreen The screen to customize.
 */
-(void)customizeAppButton:(UIButton *)appButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
/** Customize Scringo's content view (the part below the navigation bar).
 
 @param contentView The content view to customize.
 @param inScreen The screen to customize.
 */
-(void)customizeContentView:(UIView *)contentView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
/** Customize Scringo's default button style.
 
 @param aButton The button to customize.
 @param inScreen The screen to customize.
 */
-(void)customizeDefaultButtonStyle:(UIButton *)aButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;

/**---------------------------------------------------------------------------------------
 * @name General Table Cell Customization
 *  ---------------------------------------------------------------------------------------
 */

/** Customize Scringo's table cell title label.
 
 @param cellTitleLabel The table cell title label to customize.
 @param inScreen The screen to customize.
 */
-(void)customizeTableCellTitleLabel:(UILabel *)cellTitleLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeTableCellDescriptionLabel:(UILabel *)cellDescriptionLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeTableCellTimeLabel:(UILabel *)cellTimeLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeTableCellSubDescLabel:(UILabel *)cellSubDescLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeTableCellAccessoryView:(UIView *)cellAccessoryView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeTableCellFBConnectButton:(UIButton *)cellFBButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeTableCellTwitterConnectButton:(UIButton *)cellTwitterButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeTableCellSeparatorView:(UIView *)cellSeparatorView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeTableCellSelectedBackgroundView:(UIView *)selectedBackgroundView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeTableCellBadgeLabel:(UILabel *)badgeLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeTableCellBadgeImageView:(UIImageView *)badgeView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeTableCellDeleteButton:(UIButton *)deleteButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeTableCellMoreLabel:(UILabel *)moreLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeTableCellMoreImageView:(UIImageView *)moreView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeTableCellFollowButton:(UIButton *)followButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeTableCellUnfollowButton:(UIButton *)unfollowButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeTableCellCustomActionButton:(UIButton *)unfollowButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeTableCellShareButton:(UIButton *)shareButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;

/**---------------------------------------------------------------------------------------
 * @name General Table Customization
 *  ---------------------------------------------------------------------------------------
 */

/** Customize Scringo's table section header label.
 
 @param sectionHeaderLabel The table section header label to customize.
 @param inScreen The screen to customize.
 */
-(void)customizeTableSectionHeaderLabel:(UILabel *)sectionHeaderLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
/** Customize Scringo's table section header image view.
 
 @param sectionHeaderView The table section header image view to customize.
 @param inScreen The screen to customize.
 */
-(void)customizeTableSectionHeaderImageView:(UIImageView *)sectionHeaderView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
/** Customize Scringo's table section header follow button.
 
 @param followAllButton The table section header follow button to customize.
 @param inScreen The screen to customize.
 */
-(void)customizeTableSectionHeaderFollowButton:(UIButton *)followAllButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
/** Customize Scringo's table section header connect button.
 
 @param connectButton The table section header connect button to customize.
 @param inScreen The screen to customize.
 */
-(void)customizeTableSectionHeaderConnectButton:(UIButton *)connectButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;

/**---------------------------------------------------------------------------------------
 * @name Basic Dialog Customization
 *  ---------------------------------------------------------------------------------------
 */

/** Customize Scringo's dialog cancel button.
 
 @param cancelButton The dialog cancel button to customize.
 @param inScreen The screen to customize.
 */
-(void)customizeDialogCancelButton:(UIButton *)cancelButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
/** Customize Scringo's dialog send button.
 
 @param sendButton The dialog send button to customize.
 @param inScreen The screen to customize.
 */
-(void)customizeDialogSendButton:(UIButton *)sendButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;

/**---------------------------------------------------------------------------------------
 * @name Login / Signup / Share Customization
 *  ---------------------------------------------------------------------------------------
 */

/** Customize Scringo's Facebook connect button.
 
 @param facebookConnectButton The Facebook connect button to customize.
 @param inScreen The screen to customize.
 */
-(void)customizeFacebookConnectButton:(UIButton *)facebookConnectButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeFacebookSignoutButton:(UIButton *)facebookSignoutButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeFacebookConnectLogo:(UIImageView *)facebookLogo inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeTwitterConnectButton:(UIButton *)twitterConnectButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeTwitterSignoutButton:(UIButton *)twitterSignoutButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeTwitterConnectLogo:(UIImageView *)twitterLogo inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeEmailConnectButton:(UIButton *)emailConnectButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeEmailSignoutButton:(UIButton *)emailSignoutButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeEmailConnectLogo:(UIImageView *)emailConnectLogo inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeSignupConnectButton:(UIButton *)signupConnectButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeLoginConnectButton:(UIButton *)loginConnectButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeLoginHeaderLabel:(UILabel *)loginHeaderLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeLoginFooterLabel:(UILabel *)loginFooterLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;

-(void)customizeUserPhotoFrameImage:(UIImageView *)userPhotoFrameImage inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeShareView:(UIView *)shareView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;

/**---------------------------------------------------------------------------------------
 * @name Specific Buttons Customization
 *  ---------------------------------------------------------------------------------------
 */

/** Customize Scringo's cancel button.
 
 @param cancelButton The cancel button to customize.
 @param inScreen The screen to customize.
 */
-(void)customizeCancelButton:(UIButton *)cancelButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeSendButton:(UIButton *)sendButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeActionButton:(UIButton *)actionButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeDoneButton:(UIButton *)doneButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeUpdateButton:(UIButton *)updateButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeSubmitButton:(UIButton *)submitButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeChangePasswordButton:(UIButton *)changePasswordButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeForgotPasswordButton:(UIButton *)forgotPasswordButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;

/**---------------------------------------------------------------------------------------
 * @name Text Field / View Customization
 *  ---------------------------------------------------------------------------------------
 */

/** Customize Scringo's name text field.
 
 @param nameTextField The name text field to customize.
 @param inScreen The screen to customize.
 */
-(void)customizeNameTextField:(UITextField *)nameTextField inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
/** Customize Scringo's email text field.
 
 @param emailTextField The email text field to customize.
 @param inScreen The screen to customize.
 */
-(void)customizeEmailTextField:(UITextField *)emailTextField inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
/** Customize Scringo's password text field.
 
 @param passwordTextField The password text field to customize.
 @param inScreen The screen to customize.
 */
-(void)customizePasswordTextField:(UITextField *)passwordTextField inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
/** Customize Scringo's feedback text view.
 
 @param aTextView The feedback text view to customize.
 @param inScreen The screen to customize.
 */
-(void)customizeFeedbackTextView:(UITextView *)aTextView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;

/**---------------------------------------------------------------------------------------
 * @name Specific Screen Customization
 *  ---------------------------------------------------------------------------------------
 */

/** Customize Scringo's invite friends facebook button.
 
 @param facebookInviteButton The invite friends facebook button to customize.
 @param inScreen The screen to customize.
 */
-(void)customizeInviteFriendsFacebookButton:(UIButton *)facebookInviteButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeInviteFriendsTwitterButton:(UIButton *)twitterInviteButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeInviteFriendsContactButton:(UIButton *)contactInviteButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;

-(void)customizeSuggestedUsersTitleLabel:(UILabel *)titleLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeSuggestedUsersFollowButton:(UIButton *)followButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeSuggestedUsersNoSuggestionsLabel:(UILabel *)noSuggestionsLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;

-(void)customizeActivityWelcomeLabel:(UILabel *)welcomeLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeActivityMessageLabel:(UILabel *)messageLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeActivityBackgroundView:(UIImageView *)backgroundView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeActivityFollowAllButton:(UIButton *)followAllButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;

-(void)customizeInboxAnonymousNoMessagesImageView:(UIImageView *)anonymousNoMessagesImageView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeInboxComposeButton:(UIButton *)composeButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeInboxComposeFilterTextField:(UITextField *)composeFilterTextField inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;

-(void)customizeChatMyMessageTimeLabel:(UILabel *)myMessageTimeLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeChatMyMessageText:(UILabel *)myMessageText inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeChatMyMessageBackgroundImageView:(UIImageView *)myMessageBackgroundImageView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeChatOtherMessageTimeLabel:(UILabel *)otherMessageTimeLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeChatOtherMessageText:(UILabel *)otherMessageText inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeChatOtherMessageBackgroundImageView:(UIImageView *)otherMessageBackgroundImageView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeChatSendMessageButton:(UIButton *)sendMessageButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeChatUploadImageButton:(UIButton *)uploadImageButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeChatLoadEarlierButton:(UIButton *)loadEarlierButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeChatLoadEarlierBackgroundView:(UIImageView *)loadEarlierBackgroundView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;

-(void)customizeProfileView:(UIView *)profileView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeProfileNameLabel:(UILabel *)nameLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeProfileLocationLabel:(UILabel *)locationLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeProfileAboutLabel:(UILabel *)aboutLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeProfileAboutTextView:(UITextView *)aboutTextView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeProfileBadUserButton:(UIButton *)badUserButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeProfileEditAboutButton:(UIButton *)editAboutButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeProfileSettingsButton:(UIButton *)settingsButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeProfilePrivacyImageView:(UIImageView *)privacyImageView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeProfileMidBarView:(UIView *)midBarView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeProfileMidBarTopImageView:(UIImageView *)midBarTopImageView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeProfileMidBarTopShadeView:(UIImageView *)midBarShadeImageView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeProfileChatButton:(UIButton *)chatButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeProfileFollowButton:(UIButton *)followButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeProfileUnfollowButton:(UIButton *)unfollowButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;

-(void)customizeRadarAnnotationBackgroundView:(UIImageView *)backgroundView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeRadarAnnotationUserLabel:(UILabel *)userDetailsLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeRadarAnnotationAnonymousUserView:(UIImageView *)anonymousUserView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeRadarOverlayImageView:(UIImageView *)overlayImageView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeRadarNotNowButton:(UIButton *)notNowButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeRadarDontShowButton:(UIButton *)dontShowButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeRadarShowMeButton:(UIButton *)showMeButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeRadarMapButton:(UIButton *)mapButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeRadarListButton:(UIButton *)listButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeRadarFollowAllButton:(UIButton *)followAllButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;

-(void)customizeChatroomCommentBackground:(UIImageView *)commentBackground inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeChatroomDeleteButton:(UIButton *)deleteButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeChatroomPostButton:(UIButton *)postButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizePostMessageBackgroundView:(UIImageView *)postBackgroundView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeChatroomUploadImageButton:(UIButton *)uploadImageButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeChatroomHeaderTitle:(UILabel *)titleLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeChatroomHeaderTitleSeparatorView:(UIImageView *)titleSeparator inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeChatroomHeaderScrollButton:(UIButton *)scrollButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeChatroomHeaderCommentsButton:(UIButton *)commentButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;

-(void)customizeLeaderboardTodayButton:(UIButton *)todayButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeLeaderboardThisWeekButton:(UIButton *)thisWeekButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeLeaderboardAllTimeButton:(UIButton *)allTimeButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeLeaderboardUserNameLabel:(UILabel *)nameLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeLeaderboardUserLocationLabel:(UILabel *)locationLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeLeaderboardUserPositionLabel:(UILabel *)positionLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeLeaderboardUserScoreLabel:(UILabel *)scoreLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;

-(void)customizeQuizHelpButton:(UIButton *)helpButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeQuizScoreLabel:(UILabel *)scoreLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeQuizQuestionLabel:(UILabel *)questionLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeQuizAnswerButton:(UIButton *)answerButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeQuizEndOverlayImage:(UIImageView *)endOverlayImage inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeQuizGameOverLabel:(UILabel *)gameOverLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeQuizHelpPurchaseButton:(UIButton *)helpPurchaseButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeQuizPlayGameButton:(UIButton *)playGameButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeQuizStoreProductButton:(UIButton *)productButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeQuizSuggestQuestionQuestionTextView:(UITextView *)questionTextView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeQuizSuggestQuestionCorrectAnswerTextView:(UITextField *)correctAnswerTextField inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeQuizSuggestQuestionWrongAnswerTextView:(UITextField *)wrongAnswerTextField inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;

-(void)customizeStickerPackTitleLabel:(UILabel *)stickerPackTitleLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeStickerPackSubtitleLabel:(UILabel *)stickerPackSubtitleLabel inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeStickerKeyboardBackgroundView:(UIImageView *)backgroundImage inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeStickerKeyboardToolbarBackgroundView:(UIImageView *)backgroundImage inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeStickerKeyboardPageControl:(UIPageControl *)pageControl inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;

-(void)customizeWelcomeFingerSwipeLeftImageView:(UIImageView *)fingerImageView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeWelcomeFingerSwipeRightImageView:(UIImageView *)fingerImageView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;

-(void)customizeLikeOnButton:(UIButton *)likeOnButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeLikeOffButton:(UIButton *)likeOffButton inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeUsersListSearchField:(UITextField *)searchField inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;
-(void)customizeUsersListSearchIconView:(UIImageView *)searchIconView inScreen:(ScringoStyleSheetScreenIdentifier)inScreen;

@end
