# HiSpark WiFi IoT 应用程序样例

## 如何编译

修改 `build/lite/product/wifiiot.json` 文件中的：
```txt
        { "name": "wifi-iot", "dir": "//applications/sample/wifi-iot/app", "features":[] }
```
将其中的，`dir`值修改为：`"//vendor/hisi/hi3861/sample/hispark-hihope:app"` :
```txt
        { "name": "wifi-iot", "dir": "//vendor/hisi/hi3861/sample/hispark-hihope:app", "features":[] }
```
修改后，在项目根目录下执行 `python build.py wifiiot` 进行编译
