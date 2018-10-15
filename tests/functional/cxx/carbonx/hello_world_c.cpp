// Copyright (c) Microsoft. All rights reserved.
//
// Licensed under the MIT license. See LICENSE.md file in the project root for full license information.
//
// hello_world.cpp: Sample #2 - Hello World in "C" !!
//

#include "stdafx.h"

#include "carbon_test_console.h"

void CarbonTestConsole::Sample_HelloWorld_In_C()
{
     SPXHR hr = SPX_NOERROR;
     SPXSPEECHCONFIGHANDLE hconfig = SPXHANDLE_INVALID;
     if (SPX_SUCCEEDED(hr))
     {
         hr = !m_endpointUri.empty()
             ? ::speech_config_from_endpoint(&hconfig, m_endpointUri.c_str(), m_subscriptionKey.c_str())
             : ::speech_config_from_subscription(&hconfig, m_subscriptionKey.c_str(), nullptr);
     }

     if (SPX_SUCCEEDED(hr))
     {
         SPXPROPERTYBAGHANDLE bag;
         ::speech_config_get_property_bag(hconfig, &bag);
         ::property_bag_set_string(bag, -1, "SpeechServiceResponse_RequestDetailedResultTrueFalse", "false");
     }

     SPXRECOHANDLE hreco = SPXHANDLE_INVALID;
     if (SPX_SUCCEEDED(hr))
     {
         hr = ::recognizer_create_speech_recognizer_from_config(&hreco, hconfig, nullptr);
     }

     SPXASYNCHANDLE hasync = SPXHANDLE_INVALID;
     if (SPX_SUCCEEDED(hr))
     {
        ConsoleWriteLine("Say something...");
        hr = ::recognizer_recognize_once_async(hreco, &hasync);
     }

     SPXRESULTHANDLE hresult = SPXHANDLE_INVALID;
     if (SPX_SUCCEEDED(hr))
     {
        hr = ::recognizer_recognize_once_async_wait_for(hasync, 30 * 1000, &hresult);
     }

     char text[1024];
     if (SPX_SUCCEEDED(hr))
     {
        hr = ::result_get_text(hresult, text, sizeof(text) / sizeof(text[0]));
     }

     if (SPX_SUCCEEDED(hr))
     {
        ConsoleWriteLine("You said:\n\n    '%s'", text);
     }

     ::recognizer_async_handle_release(hresult);
     hasync = SPXHANDLE_INVALID;

     ::recognizer_result_handle_release(hresult);
     hresult = SPXHANDLE_INVALID;

     ::recognizer_handle_release(hreco);
     hreco = SPXHANDLE_INVALID;

     ::speech_config_release(hconfig);
     hconfig = SPXHANDLE_INVALID;
}