//
//  MainTableViewController.m
//  ScringoExample3
//
//  Created by Ofer Kalisky on 10/8/13.
//  Copyright (c) 2013 Ziggy Software. All rights reserved.
//

#import "MainTableViewController.h"
#import "DefaultSettingsViewController.h"
#import "AllUsersViewController.h"

@interface MainTableViewController ()

@end

@implementation MainTableViewController





- (void)viewDidLoad
{
    [super viewDidLoad];
    self.title = @"Chat Client Sample";

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
    return 2;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *CellIdentifier = @"Cell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:CellIdentifier];
    }
    
    // Configure the cell (ugly code...)
    if (indexPath.row == 0) {
        [cell.textLabel setText:NSLocalizedString(@"Signup / Login", nil)];
        [cell.detailTextLabel setText:NSLocalizedString(@"To use the chat you need to login", nil)];
    } else if (indexPath.row == 1) {
        [cell.textLabel setText:NSLocalizedString(@"See other users", nil)];
        [cell.detailTextLabel setText:NSLocalizedString(@"Choose a user to chat with", nil)];
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
    if (indexPath.row == 0) {
        DefaultSettingsViewController *parseVC =  [[DefaultSettingsViewController alloc] init];
        [self.navigationController pushViewController:parseVC animated:YES];
    } else if (indexPath.row == 1) {
        AllUsersViewController *allUsersVC = [[AllUsersViewController alloc] init];
        [self.navigationController pushViewController:allUsersVC animated:YES];
    }
}

@end
