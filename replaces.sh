#!/bin/bash

cp -rf replaces/x509_cert_types.cc src/net/cert/x509_cert_types.cc
cp -rf replaces/x509_cert_types.h src/net/cert/x509_cert_types.h

cp -rf replaces/cr_cronet.py src/components/cronet/tools/cr_cronet.py
cp -rf replaces/ios_sdk.gni src/build/config/ios/ios_sdk.gni