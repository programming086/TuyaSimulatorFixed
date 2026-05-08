(function () {
    window.gzlConstant = {
        deviceInfo: {
            platform: 'ios',
            pixelRatio: "##pixelRatio##",
            simulator: "##simulator##"
        },
        safeInsets: {
            top: "##safeInsetsTop##",
            left: "##safeInsetsLeft##",
            right: "##safeInsetsRight##",
            bottom: "##safeInsetsBottom##",
        },
        systemInfo: {
            language: '"##language##"',
            systemVersion:'"##systemVersion##"',
            brand:'apple',
            appVersion: '"##appVersion##"',
            containerVersion: '"##containerVersion##"',
            appName: '"##appName##"',
            appIcon: '"##appIcon##"',
            timeZone: '"##timeZone##"',
            countryCode: '"##countryCode##"',
            regionCode: '"##regionCode##"'
        },
        env: {
            kernel: '"##kernel##"',
            mode: '"##mode##"',
        },
        initialProperties: {
            TUNILocalizationManager: {}
        }
    }
})();
