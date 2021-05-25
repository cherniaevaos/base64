#include <iostream>
#include "gtest/gtest.h"
#include "main.h"

TEST(input, inputs){
    string inp = "Hello word!";

    testing::internal::CaptureStdout();
    Codding(Base64Table, inp);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "SGVsbG8gd29yZCE=");

    string inp_1 = "ABQWERTYUIOP{}ASDFGHJKL:ZXCVBNM?!1234567890+-/";

    testing::internal::CaptureStdout();
    Codding(Base64Table, inp_1);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "QUJRV0VSVFlVSU9Qe31BU0RGR0hKS0w6WlhDVkJOTT8hMTIzNDU2Nzg5MCstLw==");

    string inp_2 = "Ny kak-to tak:)";

    testing::internal::CaptureStdout();
     Codding(Base64Table, inp_2);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "Tnkga2FrLXRvIHRhazop");


    string inp_3 = "1. Crocodile is longer than green Proof: crocodile is long both on top and bottom, and green is only on top.";
    testing::internal::CaptureStdout();
     Codding(Base64Table, inp_3);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "MS4gQ3JvY29kaWxlIGlzIGxvbmdlciB0aGFuIGdyZWVuIFByb29mOiBjcm9jb2RpbGUgaXMgbG9uZyBib3RoIG9uIHRvcCBhbmQgYm90dG9tLCBhbmQgZ3JlZW4gaXMgb25seSBvbiB0b3Au");

}


TEST(out, outputs){
    string inp = "SGVsbG8gd29ybGQ=";

    testing::internal::CaptureStdout();
    Decodding(Base64Table, inp);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "Hello world");

    string inp_1 = "QUJRV0VSVFlVSU9Qe31BU0RGR0hKS0w6WlhDVkJOTT8hMTIzNDU2Nzg5MCstLw==";

    //testing::internal::CaptureStdout();
    std::string expected = "ABQWERTYUIOP{}ASDFGHJKL:ZXCVBNM?!1234567890+-/";
    Decodding(Base64Table, inp_1);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "ABQWERTYUIOP{}ASDFGHJKL:ZXCVBNM?!1234567890+-/");


    string inp_2 = "MS4gQ3JvY29kaWxlIGlzIGxvbmdlciB0aGFuIGdyZWVuIFByb29mOiBjcm9jb2RpbGUgaXMgbG9uZyBib3RoIG9uIHRvcCBhbmQgYm90dG9tLCBhbmQgZ3JlZW4gaXMgb25seSBvbiB0b3Au)";

    testing::internal::CaptureStdout();
    Decodding(Base64Table, inp_3);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "1. Crocodile is longer than green Proof: crocodile is long both on top and bottom, and green is only on top.");

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
