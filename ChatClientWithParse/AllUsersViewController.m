//
//  AllUsersViewController.m
//  ScringoExample3
//
//  Created by Ofer Kalisky on 10/8/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import "AllUsersViewController.h"
#import <Parse/Parse.h>

#import <Scringo/Scringo.h>
#import <Scringo/ScringoUser.h>

@interface AllUsersViewController ()

@end

@implementation AllUsersViewController

-(void)dealloc {
    [_allUsers release];
    [super dealloc];
}

- (void)viewDidLoad
{
    [super viewDidLoad];


    // Not really recommended to do this in the viewDidLoad, but OK for this sample
    PFQuery *query = [PFUser query];
    self.allUsers = [query findObjects];
    NSLog(@"You have %d users, I am %@", [self.allUsers count], [PFUser currentUser].username);

    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
 
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    // Return the number of rows in the section.
    return [self.allUsers count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"Cell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:CellIdentifier];
    }
    
    
    PFUser *user = [self.allUsers objectAtIndex:indexPath.row];
    [cell.textLabel setText:user.username];
    if ([[user objectId] isEqual:[[PFUser currentUser] objectId]]) {
        [cell.detailTextLabel setText:NSLocalizedString(@"This is me :-)", nil)];
    } else {
        [cell.detailTextLabel setText:NSLocalizedString(@"Click to chat", nil)];
    }
    
    [cell setAccessoryType:UITableViewCellAccessoryDisclosureIndicator];
    return cell;
}

/*
// Override to support conditional editing of the table view.
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the specified item to be editable.
    return YES;
}
*/

/*
// Override to support editing the table view.
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        // Delete the row from the data source
        [tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationFade];
    }   
    else if (editingStyle == UITableViewCellEditingStyleInsert) {
        // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
    }   
}
*/

/*
// Override to support rearranging the table view.
- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath
{
}
*/

/*
// Override to support conditional rearranging of the table view.
- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the item to be re-orderable.
    return YES;
}
*/

#pragma mark - Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    PFUser *user = [self.allUsers objectAtIndex:indexPath.row];
    if ([[user objectId] isEqual:[[PFUser currentUser] objectId]]) {
        return;
    }
    NSLog(@"Selected user scringo id is %@", [user objectForKey:@"ScringoUserId"]);
    
    [ScringoUser getUserByScringoId:[user objectForKey:@"ScringoUserId"] completion:
                                ^(ScringoUser *aUser, BOOL isSuccess) {
                                    if (isSuccess) {
                                        NSLog(@"Selected user in scringo: %@, %@", aUser.email, aUser.firstName);
                                        [Scringo openChatWithUser:aUser.userId withNavigationController:self.navigationController withScringoNavControllerEnabled:NO];
                                    } else {
                                        NSLog(@"Failed getting user");
                                    }
                                }];

    

}

@end
