#
#  Be sure to run `pod spec lint BjmobAdsSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  spec.name         = "BjmobAdsSDK"
  spec.version      = "0.0.31"
  spec.ios.deployment_target = '11.0'
  spec.platform     = :ios, "11.0"
  spec.requires_arc = true

  spec.license      = { :type => "MIT", :file => "LICENSE" }
  spec.summary      = "BjmobAdsSDK for iOS"
  spec.description  = <<-DESC
  欢迎大家使用依然在线BjmobAdsSDK, 提供成熟聚合方案。
  为开发者提供便利，快速集成。
  DESC

  spec.homepage     = "https://github.com/JiangYelinGit/BjmobAdsSDK"

  spec.author       = { "ext.jiangyelin1" => "ext.jiangyelin1@jd.com" }
  spec.source       = { :git => "https://github.com/JiangYelinGit/BjmobAdsSDK.git", :tag => "#{spec.version}" }
  
  spec.user_target_xcconfig = {'OTHER_LDFLAGS' => ['-ObjC']}
  spec.info_plist = {'GADApplicationIdentifier' => 'ca-app-pub-3940256099942544~1458002511'}

  valid_archs = ['i386', 'armv7', 'x86_64', 'arm64']

  spec.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO'}
  spec.user_target_xcconfig = { 'ENABLE_BITCODE' => 'NO'}
  
#  spec.default_subspec = 'Core'
  
  spec.requires_arc = true
#  spec.static_framework = true  #是否为静态库
  

#  spec.subspec 'Core' do |core|
#    core.source_files = 'BjmobAdsSDK/**/*.{h,m}'
#    core.frameworks = 'UIKit', 'Foundation', 'AdSupport'
#  end
#
#  spec.subspec 'Adspot' do |adspot|
#    adspot.dependency 'BjmobAdsSDK/Core'
#    adspot.source_files = 'BjmobAdsSDK/**/*.{h,m}'
#  end
  spec.resource = 'BjmobAdsSDK/Resources/GGResource.bundle'


  spec.vendored_frameworks = [
    'BjmobAdsSDK/Frameworks/Adspot/BJAdsAdspot.xcframework',
    'BjmobAdsSDK/Frameworks/core/BJAdsCore.xcframework',
    'BjmobAdsSDK/Frameworks/Adapter/BJAdsAdapter_CSJ.xcframework',
    'BjmobAdsSDK/Frameworks/Adapter/BJAdsAdapter_GDT.xcframework',
    'BjmobAdsSDK/Frameworks/Adapter/BJAdsAdapter_GG.xcframework'
  ]
  
  spec.dependency 'Ads-CN', '5.4.1.1'
  spec.dependency 'BaiduMobAdSDK', '5.311'
  spec.dependency 'GDTMobSDK', '4.14.32'
  spec.dependency 'Google-Mobile-Ads-SDK','10.9.0'
  
  spec.frameworks = 'CoreLocation', 'SystemConfiguration', 'CoreGraphics', 'CoreMotion', 'CoreTelephony', 'AdSupport', 'SystemConfiguration', 'QuartzCore', 'WebKit', 'MessageUI','SafariServices','AVFoundation','EventKit','QuartzCore','CoreMedia','StoreKit'
  spec.libraries     = 'c++'
  spec.weak_frameworks = "WebKit"
  valid_archs = ['armv7', 'armv7s', 'x86_64', 'arm64']

#  spec.subspec 'CSJ' do |csj|
#      csj.dependency 'BjmobAdsSDK/Core'
#      csj.dependency 'BjmobAdsSDK/Adspot'
#      csj.dependency 'Ads-CN'
#      csj.source_files = 'BjmobAdsSDK/**/*.{h,m}'
#      csj.frameworks = 'UIKit', 'MapKit', 'WebKit', 'MediaPlayer', 'CoreLocation', 'AdSupport', 'CoreMedia', 'AVFoundation', 'CoreTelephony', 'StoreKit', 'SystemConfiguration', 'MobileCoreServices', 'CoreMotion', 'Accelerate','AudioToolbox','JavaScriptCore','Security','CoreImage','AudioToolbox','ImageIO','QuartzCore','CoreGraphics','CoreText'
#      csj.libraries = 'c++', 'resolv', 'z', 'sqlite3', 'bz2', 'xml2', 'iconv', 'c++abi'
#      #    valid_archs = ['armv7', 'i386', 'x86_64', 'arm64']
#  end

  

  spec.xcconfig = {
    'VALID_ARCHS' =>  valid_archs.join(' '),
  }

end
