# 序
为什么非得画蛇添足要弄这个针对Xcode编译Cronet的项目，官方的不香吗？

1、因为发现chrome使用的llvm+clang在某些时候，兼容会有一些问题。

2、具体业务使用git仓库管理或者构建管理问题。

# 使用说明
1、按照官方说明，把src检出到当前git工程目录下。

2、执行replaces.sh，主要是为了解决llvm+clang和Xcode+clang的C++语法兼容问题。

3、打开Cronet.xcodeproj，进行编译即可。

4、根据具体需要情况，处理编译的产物，Framework和dSYM。

# 本项目支持Chrome版本
117.0.5914.0