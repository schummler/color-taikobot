#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <atomic>
#include <mutex>
#include <random>
void PressKey(UINT key)
{
    

    keybd_event(static_cast<BYTE>(key), 0, 0, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    keybd_event(static_cast<BYTE>(key), 0, KEYEVENTF_KEYUP, 0);

    
}
int main() {
    
    HWND hwndDesktop = GetDesktopWindow();
    HDC hdcDesktop = GetDC(hwndDesktop);
    
    std::chrono::high_resolution_clock::time_point lastNoteTime;

    bool lastKeyPressDon = false;
    bool lastKeyPressKa = false;
    bool lastKeyPressSpinner = false;
    bool botenabled = false;
    bool inslider = false;
    int delay;
    int offsetmin = 0;
    int offsetmax = 20;
    int offset;

    std::cout << "Ahorn Taiko - v0.3 B10032023\n";
    std::cout << "DELETE>  Panic Exit\n";
    std::cout << "F9>  Start Bot\n";
    std::cout << "F10>  Stop Bot\n";
    std::cout << "F11>  Show UR\n";
    std::cout << "F12> Change UR\n";
    

    while (true) {

        COLORREF currColor = GetPixel(hdcDesktop, 340, 445);
        COLORREF spinner = GetPixel(hdcDesktop, 720, 595);
        offset = rand() % offsetmax + offsetmin;
        lastNoteTime = std::chrono::high_resolution_clock::now();
        auto now = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastNoteTime);
        lastNoteTime = now;
        delay = duration.count() + offset;

        int red = GetRValue(currColor);
        int green = GetGValue(currColor);
        int blue = GetBValue(currColor);
        
       
        int sred = GetRValue(spinner);
        int sgreen = GetGValue(spinner);
        int sblue = GetBValue(spinner);
       
        
        
        if (GetAsyncKeyState(VK_F9)) {
            botenabled = true;
            std::cout << "Started!\n";
            Sleep(1000);
            system("CLS");
        }
        if (GetAsyncKeyState(VK_F10)) {
            botenabled = true;
            std::cout << "Stopped!\n" << std::flush;
            Sleep(1000);
            system("CLS");
            
        }
        if (GetAsyncKeyState(VK_F12)) {
            std::cout << "Enter min offset > ";
            std::cin >> offsetmin;
            std::cout << "Enter max offset > ";
            std::cin >> offsetmax;
        }
        
        if (GetAsyncKeyState(VK_F11)) {
            std::cout << "UR Range " << offsetmin << "ms - " << offsetmax << "ms.\n";
            Sleep(1000);

        }
        SHORT donkey;
        SHORT kakey;
        SHORT spinnerkey;

        if (botenabled) {
            if (red >= 220 && red <= 250 && green >= 60 && green <= 80 && blue >= 30 && blue <= 60)
            {
                

                if (lastKeyPressDon)
                {
                    
                    donkey = VkKeyScan('s');
                    lastKeyPressDon = false;

                }
                else
                {
                    
                    donkey = VkKeyScan('k');
                    lastKeyPressDon = true;

                }

                std::cout << "Detection> Don using " << delay << " ms offset. \n";
                std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                keybd_event(donkey, 0, 0, 0);
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                keybd_event(static_cast<BYTE>(donkey), 0, KEYEVENTF_KEYUP, 0);
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }

            if (red >= 55 && red <= 80 && green >= 130 && green <= 155 && blue >= 160 && blue <= 190) {
                

                if (lastKeyPressKa)
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                    kakey = VkKeyScan('l');
                    lastKeyPressKa = false;

                }
                else
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                    kakey = VkKeyScan('a');
                    lastKeyPressKa = true;

                }

                std::cout << "Detection> Ka using " << delay << " ms offset. \n";
                keybd_event(kakey, 0, 0, 0);
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                keybd_event(static_cast<BYTE>(kakey), 0, KEYEVENTF_KEYUP, 0);
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
            
            if (red >= 245 && red <= 255 && green >= 245 && green <= 255 && blue >= 245 && blue <= 255) {
                if (lastKeyPressKa)
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(5));
                    kakey = VkKeyScan('l');
                    lastKeyPressKa = false;

                }
                else
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(5));
                    kakey = VkKeyScan('a');
                    lastKeyPressKa = true;

                }
                std::cout << "Dectection> Slidertick Detected!\n";
                keybd_event(kakey, 0, 0, 0);
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                keybd_event(static_cast<BYTE>(kakey), 0, KEYEVENTF_KEYUP, 0);
                std::this_thread::sleep_for(std::chrono::milliseconds(5));

                
            }
            
            if (red >= 245 && red <= 255 && green >= 175 && green <= 190 && blue >= 0 && blue <= 15) {
                if (lastKeyPressKa)
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(5));
                    kakey = VkKeyScan('l');
                    lastKeyPressKa = false;

                }
                else
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(5));
                    kakey = VkKeyScan('a');
                    lastKeyPressKa = true;

                }
                std::cout << "Dectection> Slider Detected!\n";
                keybd_event(kakey, 0, 0, 0);
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                keybd_event(static_cast<BYTE>(kakey), 0, KEYEVENTF_KEYUP, 0);
                std::this_thread::sleep_for(std::chrono::milliseconds(1));


            }
            if (sred >= 195 && sred <= 210 && sgreen >= 0 && sgreen <= 10 && sblue >= 170 && sblue <= 185) {
                

                if (lastKeyPressSpinner)
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(1));
                    spinnerkey = VkKeyScan('l');
                    lastKeyPressSpinner = false;

                }
                else
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(1));
                    spinnerkey = VkKeyScan('k');
                    lastKeyPressSpinner = true;

                }
                std::cout << "Dectection> Spinner Detected!\n";
                keybd_event(spinnerkey, 0, 0, 0);
                std::this_thread::sleep_for(std::chrono::milliseconds(5));
                keybd_event(spinnerkey, 0, KEYEVENTF_KEYUP, 0);
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }

        
        }

    }
            

            
            
        

        
        
    

    
    ReleaseDC(hwndDesktop, hdcDesktop);

    return 0;
}
