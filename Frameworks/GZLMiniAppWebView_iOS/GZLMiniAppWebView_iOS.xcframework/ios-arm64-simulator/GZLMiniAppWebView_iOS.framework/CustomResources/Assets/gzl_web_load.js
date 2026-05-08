const __gslsendcallbackMap__ = {}
const __gslnativesendcallbackMap__ = {}
let __gslcallbackNum__ = 0;
let __gslnativeCallbackNum__ = 0;
if (window.gzlJSBridge === undefined) {
    window.gzlJSBridge = {}
}

function __gslsendmsgcallback__(num, value) {
    if (__gslsendcallbackMap__[num]) {
        __gslsendcallbackMap__[num](value)
        delete __gslsendcallbackMap__[num]
    }
}

function __gslsendmsgnativecallback__(num, value) {
    if (__gslnativesendcallbackMap__[num]) {
        __gslnativesendcallbackMap__[num](value)
        delete __gslnativesendcallbackMap__[num]
    }
}

function __gslwebviewinvoke__(args, callback) {
    __gslcallbackNum__ = __gslcallbackNum__ - 1;
    if (callback !== undefined) {
        window.webkit.messageHandlers.channel.postMessage({
            args: args,
            num: __gslcallbackNum__,
        })
        __gslsendcallbackMap__[__gslcallbackNum__] = callback
    } else  {
        window.webkit.messageHandlers.channel.postMessage({
            args: args,
            num: __gslcallbackNum__,
        })
    }
}

function __gslwebnativeinvoke__(args, callback) {
    __gslnativeCallbackNum__ = __gslnativeCallbackNum__ - 1;
    if (callback !== undefined) {
        window.webkit.messageHandlers.nativeInvoke.postMessage({
            args: args,
            num: __gslnativeCallbackNum__,
        })
        __gslnativesendcallbackMap__[__gslnativeCallbackNum__] = callback
    } else  {
        window.webkit.messageHandlers.nativeInvoke.postMessage({
            args: args,
            num: __gslnativeCallbackNum__,
        })
    }
}

function __gslwebviewinvokenative__(action, data) {
    window.webkit.messageHandlers.viewInvokeNative.postMessage({
        'action':action,
        'data':data
    })
}

function __gzlHandlerBack__(code) {
    return (args)=> {
        window.webkit.messageHandlers.invokeBack.postMessage({
            'code': code,
            'args': args,
        })
    };
}

function __webviewonviewloaded__(webviewId) {
    window.webkit.messageHandlers.webviewOnViewLoaded.postMessage({'webviewId':webviewId});
}

window.gzlJSBridge.viewInvoke = __gslwebviewinvoke__;
window.gzlJSBridge.nativeInvoke = __gslwebnativeinvoke__;
window.gzlJSBridge.viewInvokeNative = __gslwebviewinvokenative__;
window.__VIEW_LOADED__ = __webviewonviewloaded__;

window.gzlJSBridge.onNativeDomChange =  (script) => {
    window.webkit.messageHandlers.onNativeDomChange.postMessage(script);
}
