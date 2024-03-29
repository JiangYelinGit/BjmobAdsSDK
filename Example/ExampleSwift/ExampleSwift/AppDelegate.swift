//
//  AppDelegate.swift
//  swift_demo
//
//  Created by ext.jiangyelin1 on 2023/7/12.
//

import UIKit
import BJAdsCore
import Bugly

@main
class AppDelegate: UIResponder, UIApplicationDelegate {

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        var buglyConfig = BuglyConfig()
        buglyConfig.debugMode = false
        Bugly.start(withAppId: "cb8f7f8543", config: buglyConfig)
        
        
      
        
        self.settingBJAds()
        return true
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
        
    }

    func settingBJAds() {
        BJAdSdkConfig.shareInstance().level = .debug;
        let model = BJConfigModel();
        model.debugMode = false;
        BJAdSdkConfig.shareInstance().registerAppID("a06460e31fce62fa", withConfig: model)
    }
}

