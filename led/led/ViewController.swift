//
//  ViewController.swift
//  led
//
//  Created by Oskar Niburski on 2014-11-22.
//  Copyright (c) 2014 Oskar Niburski. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet weak var reloadButton: UIButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // initial load
    }
    
    // when the reload button tapped
    @IBAction func reloadDidTap(sender: AnyObject) {
        reloadled()
    }
    
    // call the API, parse the response and show result
    private func reloadled() {
        var request = NSMutableURLRequest(URL: NSURL(string: "https://api.spark.io/v1/devices/53ff6b066667574852212367/led")!)
        var session = NSURLSession.sharedSession()
        request.HTTPMethod = "POST"
        request.HTTPBody = "access_token=94f2788badb6634bc483fc1efe541e810280b9da&params=l1,HIGH".dataUsingEncoding(NSUTF8StringEncoding)
        
        var task = session.dataTaskWithRequest(request, completionHandler: {data, response, error -> Void in
            println("Response: \(response)")
            var strData = NSString(data: data, encoding: NSUTF8StringEncoding)
            println("Body: \(strData)")
        })
        
        task.resume()
        
    }
}
