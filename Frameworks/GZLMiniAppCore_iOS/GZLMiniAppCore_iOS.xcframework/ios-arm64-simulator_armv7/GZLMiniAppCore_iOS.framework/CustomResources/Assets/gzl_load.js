(function () {
    if (typeof globalThis === 'undefined') {
        window = this
    } else {
        window = globalThis
    }
    if (window.gzlJSBridge === undefined) {
        window.gzlJSBridge = {}
        if (window.gzlJSBridge.appChannel === undefined) {
            window.gzlJSBridge.appChannel = {}
        }
        window.gzlJSBridge.call = __gzlCall__
        window.__gzlHandlerBack__ = (pageId, code) => {
            if (typeof code === 'undefined' || code === null || pageId === null || typeof pageId === 'undefined') {
                return null
            }
            return (args)=> {
                if (typeof args === 'undefined') args = ''
                __gzlHandlerCallback__(pageId, code, args);
            };
        }
        function __gzlCall__(module, method, params, success, fail) {
            if (method.endsWith("Sync")) {
                const res = window.gzlJSBridge.callNativeSync(module, method, params);
                return res;
            }
            const successFunc = success;
            const failFunc = fail;
            return new Promise((resolve, reject) => {
                window.gzlJSBridge.callNativeAsync(module, method, params, {
                    success: function (res) {
                        if (successFunc && typeof successFunc === "function")
                            successFunc(res);
                        resolve(res);
                    },
                    fail: function (res) {
                        if (failFunc && typeof failFunc === "function") failFunc(res);
                        resolve(res);
                    },
                });
            });
        }
    }
})();
