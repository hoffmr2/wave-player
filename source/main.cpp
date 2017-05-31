#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include "res.h"
#include <thread>
#include "wave_player.h"
#include "open_file_dialog.h"




/*
 * User globals
 */
HWND hwnd_main_window;

/*
 * User functions
 */






LPCSTR path;
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch (uMsg)
  {
  case WM_COMMAND:
    switch (HIWORD(wParam))
    {
    case BN_CLICKED:
      switch (LOWORD(wParam))
      {
      case IDC_BUTTON_START:
        return TRUE;

      case IDC_BUTTON_PLAY:
        auto hwnd_edit_notes = GetDlgItem(hwndDlg, IDC_EDIT_NOTES);
        //  int value;
        INT text_length = GetWindowTextLength(hwnd_edit_notes);
        CHAR notes[500];
        GetWindowText(hwnd_edit_notes, notes, text_length);
       
        if (wavePlayer->isPlaying == TRUE)
        {
          wavePlayer->Stop();
          return TRUE;
        }


        OpenFileDialog* openFileDialog1 = new OpenFileDialog();
          openFileDialog1->FilterIndex = 1;
        openFileDialog1->Flags |= OFN_SHOWHELP;
        openFileDialog1->InitialDir = _T("C:\\Windows\\");
        openFileDialog1->Title = _T("Open Text File");

        if (!openFileDialog1->ShowDialog())
        {
          return FALSE;
        }
      
        wavePlayer->Play(openFileDialog1->FileName);

        /*
        * try and open the file
        */
       
        
        return TRUE;
      }



    }
    return FALSE;
  case WM_INITDIALOG:
    wavePlayer = new WavePlayer(hwndDlg);

    path = "../jazz.wav";


    return TRUE;
  case WM_CLOSE:
    DestroyWindow(hwndDlg);
    PostQuitMessage(0);
    return TRUE;
  }
  return FALSE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{


  hwnd_main_window = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAINVIEW), NULL, DialogProc);
  ShowWindow(hwnd_main_window, iCmdShow);
  MSG msg = {};



 
 
  /*
  * set up the WAVEFORMATEX structure.
  */



  /*
  * wait for all blocks to complete
  */
  //while (waveFreeBlockCount < BLOCK_COUNT)
 //  Sleep(10);
  /*
  * unprepare any blocks that are still prepared
  */



  while (GetMessage(&msg, NULL, 0, 0))
  {

    TranslateMessage(&msg);
    DispatchMessage(&msg);

  }
//  for (i = 0; i < waveFreeBlockCount; i++)
  //  if (waveBlocks[i].dwFlags & WHDR_PREPARED)
//      waveOutUnprepareHeader(hWaveOut, &waveBlocks[i], sizeof(WAVEHDR));
//  DeleteCriticalSection(&waveCriticalSection);
//  freeBlocks(waveBlocks);
//  waveOutClose(hWaveOut);
//  CloseHandle(hFile);
  return 0;
}




