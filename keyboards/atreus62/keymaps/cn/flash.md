# Notes: How to flash RP2040

1. Connect keyboard
2. Put keyboard into bootloader mode
3. Keyboard should mount as Mass Storage USB
4. Compile firmware

    ```bash
    qmk compile -c -kb atreus62 -km cn -e CONVERT_TO=promicro_rp2040
    ```

    Should generate a file named `atreus62_cn_promicro_rp2040.uf2`.

5. Open USB drive in a file browser
6. Drag and drop the utf2 file onto the drive
7. The USB drive should now disconnect and reconnect as a keyboard device with the new firmware

## Tip

If you forgot to pull with submodules, you can fetch them post clone with

```bash
git submodule update --init
```
