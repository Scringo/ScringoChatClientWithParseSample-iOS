//
//  ScringoStyleSheetProtocol.h
//  ScringoExample3
//
//  Created by Ofer Kalisky on 9/30/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    SCRINGO_STYLE_SCREEN_LIKE_BUTTON,
    SCRINGO_STYLE_SCREEN_FOLLOWERS,
    SCRINGO_STYLE_SCREEN_PANEL,
    SCRINGO_STYLE_SCREEN_INBOX,
    SCRINGO_STYLE_SCREEN_COMPOSE,
    SCRINGO_STYLE_SCREEN_ACTIVITY,
    SCRINGO_STYLE_SCREEN_SUGGESTED_PEOPLE,
    SCRINGO_STYLE_SCREEN_FEEDBACK_MAIN,
    SCRINGO_STYLE_SCREEN_FEEDBACK_TALKTOUS,
    SCRINGO_STYLE_SCREEN_FIND_INVITE_MAIN,
    SCRINGO_STYLE_SCREEN_FIND_FRIENDS,
    SCRINGO_STYLE_SCREEN_INVITE_FRIENDS,
    SCRINGO_STYLE_SCREEN_SUGGESTED_USERS,
    SCRINGO_STYLE_SCREEN_CHAT,
    SCRINGO_STYLE_SCREEN_OTHER_PROFILE,
    SCRINGO_STYLE_SCREEN_MY_PROFILE,
    SCRINGO_STYLE_SCREEN_EDIT_BIO,
    SCRINGO_STYLE_SCREEN_RADAR_ANNOTATION,
    SCRINGO_STYLE_SCREEN_RADAR,
    SCRINGO_STYLE_SCREEN_FULL_SCREEN_IMAGE,
    SCRINGO_STYLE_SCREEN_SYSTEM_MESSAGE,
    SCRINGO_STYLE_SCREEN_CHATROOMS_LIST,
    SCRINGO_STYLE_SCREEN_CHATROOM,
    SCRINGO_STYLE_SCREEN_LEADERBOARD,
    SCRINGO_STYLE_SCREEN_SIGNUP,
    SCRINGO_STYLE_SCREEN_LOGIN,
    SCRINGO_STYLE_SCREEN_EMAIL_SIGNUP,
    SCRINGO_STYLE_SCREEN_EMAIL_LOGIN,
    SCRINGO_STYLE_SCREEN_USER_SETTINGS,
    SCRINGO_STYLE_SCREEN_QUIZ_MAIN,
    SCRINGO_STYLE_SCREEN_QUIZZES,
    SCRINGO_STYLE_SCREEN_QUIZ,
    SCRINGO_STYLE_SCREEN_QUIZ_STORE,
    SCRINGO_STYLE_SCREEN_QUIZ_SUGGEST_QUESTION,
    SCRINGO_STYLE_SCREEN_STICKER_PACK,
    SCRINGO_STYLE_SCREEN_STICKER_STORE,
    SCRINGO_STYLE_SCREEN_STICKER_KEYBOARD
} ScringoStyleSheetScreeenIdentifier;

@protocol ScringoStyleSheetProtocol <NSObject>

@optional
-(void)customizeBackgroundView:(UIImageView *)backgroundView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeNavbarView:(UIView *)navView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeNavBarImageView:(UIImageView *)navImageView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeScreenTitleLabel:(UILabel *)screenTitleLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeBackButton:(UIButton *)backButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeAppButton:(UIButton *)appButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeContentView:(UIView *)contentView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeDefaultButtonStyle:(UIButton *)aButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;

-(void)customizeTableCellTitleLabel:(UILabel *)cellTitleLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTableCellDescriptionLabel:(UILabel *)cellDescriptionLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTableCellTimeLabel:(UILabel *)cellTimeLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTableCellSubDescLabel:(UILabel *)cellSubDescLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTableCellAccessoryView:(UIView *)cellAccessoryView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTableCellFBConnectButton:(UIButton *)cellFBButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTableCellTwitterConnectButton:(UIButton *)cellTwitterButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTableCellSeparatorView:(UIView *)cellSeparatorView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTableCellSelectedBackgroundView:(UIView *)selectedBackgroundView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTableCellBadgeLabel:(UILabel *)badgeLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTableCellBadgeImageView:(UIImageView *)badgeView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTableCellDeleteButton:(UIButton *)deleteButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTableCellMoreLabel:(UILabel *)moreLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTableCellMoreImageView:(UIImageView *)moreView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTableCellFollowButton:(UIButton *)followButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTableCellUnfollowButton:(UIButton *)unfollowButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTableCellCustomActionButton:(UIButton *)unfollowButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTableCellShareButton:(UIButton *)shareButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;

-(void)customizeTableSectionHeaderLabel:(UILabel *)sectionHeaderLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTableSectionHeaderImageView:(UIImageView *)sectionHeaderView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTableSectionHeaderFollowButton:(UIButton *)followAllButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTableSectionHeaderConnectButton:(UIButton *)connectButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;

-(void)customizeDialogCancelButton:(UIButton *)cancelButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeDialogSendButton:(UIButton *)sendButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;

-(void)customizeFacebookConnectButton:(UIButton *)facebookConnectButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeFacebookSignoutButton:(UIButton *)facebookSignoutButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeFacebookConnectLogo:(UIImageView *)facebookLogo inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTwitterConnectButton:(UIButton *)twitterConnectButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTwitterSignoutButton:(UIButton *)twitterSignoutButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeTwitterConnectLogo:(UIImageView *)twitterLogo inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeEmailConnectButton:(UIButton *)emailConnectButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeEmailSignoutButton:(UIButton *)emailSignoutButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeEmailConnectLogo:(UIImageView *)emailConnectLogo inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeSignupConnectButton:(UIButton *)signupConnectButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeLoginConnectButton:(UIButton *)loginConnectButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeLoginHeaderLabel:(UILabel *)loginHeaderLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeLoginFooterLabel:(UILabel *)loginFooterLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;

-(void)customizeUserPhotoFrameImage:(UIImageView *)userPhotoFrameImage inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeShareView:(UIView *)shareView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;

-(void)customizeCancelButton:(UIButton *)cancelButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeSendButton:(UIButton *)sendButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeActionButton:(UIButton *)actionButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeDoneButton:(UIButton *)doneButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeUpdateButton:(UIButton *)updateButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeSubmitButton:(UIButton *)submitButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeChangePasswordButton:(UIButton *)changePasswordButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeForgotPasswordButton:(UIButton *)forgotPasswordButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;

-(void)customizeNameTextField:(UITextField *)nameTextField inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeEmailTextField:(UITextField *)emailTextField inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizePasswordTextField:(UITextField *)passwordTextField inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;

-(void)customizeFeedbackTextView:(UITextView *)aTextView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;

-(void)customizeInviteFriendsFacebookButton:(UIButton *)facebookInviteButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeInviteFriendsTwitterButton:(UIButton *)twitterInviteButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeInviteFriendsContactButton:(UIButton *)contactInviteButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;

-(void)customizeSuggestedUsersTitleLabel:(UILabel *)titleLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeSuggestedUsersFollowButton:(UIButton *)followButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeSuggestedUsersNoSuggestionsLabel:(UILabel *)noSuggestionsLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;

-(void)customizeActivityWelcomeLabel:(UILabel *)welcomeLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeActivityMessageLabel:(UILabel *)messageLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeActivityBackgroundView:(UIImageView *)backgroundView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeActivityFollowAllButton:(UIButton *)followAllButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;

-(void)customizeInboxAnonymousNoMessagesImageView:(UIImageView *)anonymousNoMessagesImageView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeInboxComposeButton:(UIButton *)composeButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeInboxComposeFilterTextField:(UITextField *)composeFilterTextField inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;

-(void)customizeChatMyMessageTimeLabel:(UILabel *)myMessageTimeLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeChatMyMessageText:(UILabel *)myMessageText inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeChatMyMessageBackgroundImageView:(UIImageView *)myMessageBackgroundImageView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeChatOtherMessageTimeLabel:(UILabel *)otherMessageTimeLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeChatOtherMessageText:(UILabel *)otherMessageText inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeChatOtherMessageBackgroundImageView:(UIImageView *)otherMessageBackgroundImageView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeChatSendMessageButton:(UIButton *)sendMessageButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeChatUploadImageButton:(UIButton *)uploadImageButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeChatLoadEarlierButton:(UIButton *)loadEarlierButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeChatLoadEarlierBackgroundView:(UIImageView *)loadEarlierBackgroundView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;

-(void)customizeProfileView:(UIView *)profileView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeProfileNameLabel:(UILabel *)nameLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeProfileLocationLabel:(UILabel *)locationLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeProfileAboutLabel:(UILabel *)aboutLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeProfileAboutTextView:(UITextView *)aboutTextView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeProfileBadUserButton:(UIButton *)badUserButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeProfileEditAboutButton:(UIButton *)editAboutButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeProfileSettingsButton:(UIButton *)settingsButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeProfilePrivacyImageView:(UIImageView *)privacyImageView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeProfileMidBarView:(UIView *)midBarView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeProfileMidBarTopImageView:(UIImageView *)midBarTopImageView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeProfileMidBarTopShadeView:(UIImageView *)midBarShadeImageView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeProfileChatButton:(UIButton *)chatButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeProfileFollowButton:(UIButton *)followButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeProfileUnfollowButton:(UIButton *)unfollowButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;

-(void)customizeRadarAnnotationBackgroundView:(UIImageView *)backgroundView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeRadarAnnotationUserLabel:(UILabel *)userDetailsLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeRadarAnnotationAnonymousUserView:(UIImageView *)anonymousUserView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeRadarOverlayImageView:(UIImageView *)overlayImageView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeRadarNotNowButton:(UIButton *)notNowButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeRadarDontShowButton:(UIButton *)dontShowButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeRadarShowMeButton:(UIButton *)showMeButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeRadarMapButton:(UIButton *)mapButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeRadarListButton:(UIButton *)listButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeRadarFollowAllButton:(UIButton *)followAllButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;

-(void)customizeChatroomCommentBackground:(UIImageView *)commentBackground inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeChatroomDeleteButton:(UIButton *)deleteButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeChatroomPostButton:(UIButton *)postButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizePostMessageBackgroundView:(UIImageView *)postBackgroundView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeChatroomUploadImageButton:(UIButton *)uploadImageButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeChatroomHeaderTitle:(UILabel *)titleLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeChatroomHeaderTitleSeparatorView:(UIImageView *)titleSeparator inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeChatroomHeaderScrollButton:(UIButton *)scrollButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeChatroomHeaderCommentsButton:(UIButton *)commentButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;

-(void)customizeLeaderboardTodayButton:(UIButton *)todayButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeLeaderboardThisWeekButton:(UIButton *)thisWeekButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeLeaderboardAllTimeButton:(UIButton *)allTimeButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeLeaderboardUserNameLabel:(UILabel *)nameLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeLeaderboardUserLocationLabel:(UILabel *)locationLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeLeaderboardUserPositionLabel:(UILabel *)positionLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeLeaderboardUserScoreLabel:(UILabel *)scoreLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;

-(void)customizeQuizHelpButton:(UIButton *)helpButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeQuizScoreLabel:(UILabel *)scoreLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeQuizQuestionLabel:(UILabel *)questionLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeQuizAnswerButton:(UIButton *)answerButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeQuizEndOverlayImage:(UIImageView *)endOverlayImage inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeQuizGameOverLabel:(UILabel *)gameOverLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeQuizHelpPurchaseButton:(UIButton *)helpPurchaseButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeQuizPlayGameButton:(UIButton *)playGameButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeQuizStoreProductButton:(UIButton *)productButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeQuizSuggestQuestionQuestionTextView:(UITextView *)questionTextView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeQuizSuggestQuestionCorrectAnswerTextView:(UITextField *)correctAnswerTextField inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeQuizSuggestQuestionWrongAnswerTextView:(UITextField *)wrongAnswerTextField inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;

-(void)customizeStickerPackTitleLabel:(UILabel *)stickerPackTitleLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeStickerPackSubtitleLabel:(UILabel *)stickerPackSubtitleLabel inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeStickerKeyboardBackgroundView:(UIImageView *)backgroundImage inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeStickerKeyboardToolbarBackgroundView:(UIImageView *)backgroundImage inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeStickerKeyboardPageControl:(UIPageControl *)pageControl inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;

-(void)customizeWelcomeFingerSwipeLeftImageView:(UIImageView *)fingerImageView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeWelcomeFingerSwipeRightImageView:(UIImageView *)fingerImageView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;

-(void)customizeLikeOnButton:(UIButton *)likeOnButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeLikeOffButton:(UIButton *)likeOffButton inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeUsersListSearchField:(UITextField *)searchField inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;
-(void)customizeUsersListSearchIconView:(UIImageView *)searchIconView inScreen:(ScringoStyleSheetScreeenIdentifier)inScreen;

@end
