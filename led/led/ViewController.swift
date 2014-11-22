//
//  ViewController.swift
//  led
//
//  Created by Oskar Niburski on 2014-11-22.
//  Copyright (c) 2014 Oskar Niburski. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    let device_id = "53ff6b066667574852212367"
    let access_token = "94f2788badb6634bc483fc1efe541e810280b9da"
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = UIColor(red: 0.145, green: 0.145, blue: 0.145, alpha: 1.0)
        
        let screenWidth = UIScreen.mainScreen().bounds.size.width
        let screenHeight = UIScreen.mainScreen().bounds.size.height
        
        self.view.addSubview(createCircle(100, color:UIColor(red:0, green:0, blue:0, alpha: 1.0)))
        self.view.addSubview(createCircle(95, color:UIColor(red: 0.145, green: 0.145, blue: 0.145, alpha: 1.0)))
        self.view.addSubview(createCircle(85, color:UIColor(red:0, green:0, blue:0, alpha: 1.0)))
        self.view.addSubview(createCircle(80, color:UIColor(red:0.808, green:0.906, blue:0.271, alpha:1.0)))
        
        
        let button = UIButton.buttonWithType(UIButtonType.Custom) as UIButton
        button.frame = CGRectMake(
            (screenWidth - 100) / 2.0,
            (screenHeight - 100) / 2.0,
            100,
            100)
        button.setTitle("Button1", forState: UIControlState.Normal)
        button.titleLabel!.font = UIFont.boldSystemFontOfSize(22)
        button.addTarget(self, action: "pressedButton1:", forControlEvents: .TouchUpInside)
        self.view.addSubview(button)
        
    }
    
    func pressedButton1(sender: UIButton!)
    {
        
        var request = NSMutableURLRequest(URL: NSURL(string: "https://api.spark.io/v1/devices/\(device_id)/led")!)
        var session = NSURLSession.sharedSession()
        request.HTTPMethod = "POST"
        request.HTTPBody = "access_token=\(access_token)&params=l1,HIGH".dataUsingEncoding(NSUTF8StringEncoding)
        
        var task = session.dataTaskWithRequest(request, completionHandler: {data, response, error -> Void in
            println("Response: \(response)")
            var strData = NSString(data: data, encoding: NSUTF8StringEncoding)
            println("Body: \(strData)")
        })
        
        task.resume()
    }
    
    func pressedButton2(sender: UIButton!)
    {
        
        var request = NSMutableURLRequest(URL: NSURL(string: "https://api.spark.io/v1/devices/\(device_id)/led")!)
        var session = NSURLSession.sharedSession()
        request.HTTPMethod = "POST"
        request.HTTPBody = "access_token=\(access_token)&params=l2,HIGH".dataUsingEncoding(NSUTF8StringEncoding)
        
        var task = session.dataTaskWithRequest(request, completionHandler: {data, response, error -> Void in
            println("Response: \(response)")
            var strData = NSString(data: data, encoding: NSUTF8StringEncoding)
            println("Body: \(strData)")
        })
        
        task.resume()
    }
    
    private func createCircle(radius: CGFloat, color: UIColor) -> UIView
    {
        let screenWidth = UIScreen.mainScreen().bounds.size.width
        let screenHeight = UIScreen.mainScreen().bounds.size.height
        let x = (screenWidth - radius) / 2.0
        let y = (screenHeight - radius) / 2.0
        
        let circle = UIView(frame: CGRectMake(x, y, radius, radius))
        circle.alpha = 0.5
        circle.layer.cornerRadius = radius / 2.0
        circle.backgroundColor = color
        return circle
    }
}