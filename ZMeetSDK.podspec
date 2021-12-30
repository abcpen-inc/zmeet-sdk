Pod::Spec.new do |s|
  s.name             = "ZMeetSDK"
  s.version          = "0.0.1"
  s.summary          = "ZMeetSDK."
  s.description      = "ZMeetSDK of bing"
  s.homepage         = "http://www.abcpen.com"
  s.license          = 'MIT'
  s.author           = { "bing" => "bing@abcpen.com" }
  s.source           = { :git => 'https://github.com/abcpen-inc/zmeet-sdk.git',:tag => s.version}
  s.platform         = :ios, '10.0'
  s.requires_arc     = true
  s.pod_target_xcconfig = { 'VALID_ARCHS' => 'armv7'}

  s.subspec 'ZmeetCoreKit' do |sp|
    sp.public_header_files = 'ZMeetSDK/ZmeetCoreKit.framework/Headers/ZmeetCoreKit.h'
    sp.source_files        = 'ZMeetSDK/ZmeetCoreKit.framework/Headers/*.{h}'
    sp.vendored_frameworks = 'ZMeetSDK/ZmeetCoreKit.framework'
    sp.dependency 'AFNetworking'
    sp.dependency 'Masonry'
    sp.dependency 'JSONModel'

    sp.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' }
  end

  s.subspec 'ZmeetPhotoKit' do |sp|
    sp.public_header_files = 'ZMeetSDK/ZmeetPhotoKit.framework/Headers/ZmeetPhotoKit.h'
    sp.source_files        = 'ZMeetSDK/ZmeetPhotoKit.framework/Headers/*.{h}'
    sp.vendored_frameworks = 'ZMeetSDK/ZmeetPhotoKit.framework'
    sp.dependency 'AFNetworking'
    sp.dependency 'Masonry'
    sp.dependency 'GPUImage'
    sp.dependency 'JSONModel'
    sp.dependency 'Toast'
    sp.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' }
  end

end
