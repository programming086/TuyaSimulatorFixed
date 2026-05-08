# Tuya Smart Home iOS SDK - arm64 Simulator Support

This repository contains patched versions of Tuya Smart Home iOS SDK frameworks with arm64 simulator support.

## Installation

Add this to your `Podfile`:

```ruby
source 'https://github.com/programming086/TuyaSimulatorFixed.git'
source 'https://github.com/CocoaPods/Specs.git'

platform :ios, '11.0'

target 'YourApp' do
  use_frameworks!
  pod 'TuyaSmartActivatorKit'
end
```

## What's Different?

- ✅ arm64 simulator support (Apple Silicon Macs)
- ✅ All original functionality preserved
- ✅ Same API as official SDK

## Available Frameworks

Check the `Specs/` directory for all available frameworks.

## Updates

To update to a new version of the official SDK, re-run the patching scripts.
