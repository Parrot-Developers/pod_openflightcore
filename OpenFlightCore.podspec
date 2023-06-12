Pod::Spec.new do |s|
  s.name                  = "OpenFlightCore"
  s.version               = "7.7.0-rc1"
  s.summary               = "Parrot Drone OpenFlightCore, low level implementation"
  s.homepage              = "https://developer.parrot.com"
  s.license               = "{ :type => 'BSD 3-Clause License', :file => 'LICENSE' }"
  s.author                = "Parrot Drone SAS"
  s.source                = { :git => 'https://github.com/Parrot-Developers/pod_openflightcore', :tag => "7.7.0-rc1" }
  s.platform              = :ios
  s.ios.deployment_target = '13.0'
  s.vendored_frameworks   = 'OpenFlightCore.framework'
  s.xcconfig              = { 'ONLY_ACTIVE_ARCH' => 'YES' }
end
