# Proccess-Authorization [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A Simple tool to prevent others using your personal software or tools on regular startup.

## Install

- Download the current master branch.

  - Using **Git CLI**..

    ```shell
    > git clone https://github.com/raja-ravi-prakash/Proccess-Authorization
    ```

  - Use the provided [download](https://github.com/raja-ravi-prakash/Proccess-Authorization/archive/master.zip) option from github.

  - And you also need [GCC Compiler](https://sourceforge.net/projects/mingw/) to run C language parts, For instructions visit [this](https://www.youtube.com/watch?v=Ubfgi4NoTPk).

## How To

- From the root folder run **build.bat** which prompts you for the no.of programs names of them which you want to restrict.
- And it prompts you for a password, so you can use it later to deactivate current running session.

  ```shell
  > build # Example
    Enter no.of Programs : 3 # 3 Programs are given

    Enter Program names followed by Extensions
    Enter Program Name : Bluestacks.exe # valid extensions with valid names should be mentioned.
    Enter Program Name : chrome.exe
    Enter Program Name : notepad.exe
    # And this creates a dist folder with required files...

    Create Password: <your password>
  ```

  **Note :**

  - If you don't know the valid name with extension of your program (or) software quick way is , run it in your system manually and
    run this command in **cmd** (or) **powershell** .

    ```shell
    > tasklist
    ```

  - The above command shows you all the running process try and find your own.

  - Another way is look in the installation directory of your software you can find it .

## Configure

- If you want to reset and create a new build, below command does that for you. so, after for regeneration use **build**.

  ```shell
  > clean
  ```

- That's it on regular boot no one can run these files, for you to run it below can do that.

  ```shell
  > %ronin%_s <your_password> # without <>
  ```

- And fell free to contribue (or) create an issue if something doesn't work as expected.

## LICENSE

    MIT License

    Copyright (c) 2020 Raja Ravi Prakash

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
