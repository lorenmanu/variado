# webview apk
## Description
Simple Android project with a webview, it can view a webpage inside the apk
like a web browser, the back key is set to not exit and the links open the new
web inside the webview, this is useful to show a webapp for mobile.
In the example i did a webapp using django and bootstrap, and with the webview
i load the url of my webapp and you can put your apk in playstore or similar.
Another advantage is that if you update the webapp, the cliente see in real time the changes,
dont need to download a new version of the apk.

Only if you add a new function that need new permissions you must to update de manifest.xml, but
is the only case.
