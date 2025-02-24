// Target definition
#define RG_TARGET_NAME             "ESPLAY-S3"

// Storage
#define RG_STORAGE_ROOT             "/sd"
#define RG_STORAGE_SDSPI_HOST       SPI3_HOST
#define RG_STORAGE_SDSPI_SPEED      SDMMC_FREQ_DEFAULT

// Audio
#define RG_AUDIO_USE_INT_DAC        0   // 0 = Disable, 1 = GPIO25, 2 = GPIO26, 3 = Both
#define RG_AUDIO_USE_EXT_DAC        1   // 0 = Disable, 1 = Enable

// Video
#define RG_SCREEN_DRIVER            0   // 0 = ILI9341
#define RG_SCREEN_HOST              SPI2_HOST
#define RG_SCREEN_SPEED             SPI_MASTER_FREQ_40M
#define RG_SCREEN_BACKLIGHT         1
#define RG_SCREEN_WIDTH             320
#define RG_SCREEN_HEIGHT            240
#define RG_SCREEN_ROTATE            180
#define RG_SCREEN_MARGIN_TOP        0
#define RG_SCREEN_MARGIN_BOTTOM     0
#define RG_SCREEN_MARGIN_LEFT       0
#define RG_SCREEN_MARGIN_RIGHT      0
#define RG_SCREEN_INIT()                                                                                           \
    ILI9341_CMD(0xCF, 0x00, 0xc3, 0x30);                                                                         \
    ILI9341_CMD(0xED, 0x64, 0x03, 0x12, 0x81);                                                                   \
    ILI9341_CMD(0xE8, 0x85, 0x00, 0x78);                                                                         \
    ILI9341_CMD(0xCB, 0x39, 0x2c, 0x00, 0x34, 0x02);                                                             \
    ILI9341_CMD(0xF7, 0x20);                                                                                     \
    ILI9341_CMD(0xEA, 0x00, 0x00);                                                                               \
    ILI9341_CMD(0xC0, 0x1B);                    /* Power control   //VRH[5:0] */                                    \
    ILI9341_CMD(0xC1, 0x12);                    /* Power control   //SAP[2:0];BT[3:0] */                            \
    ILI9341_CMD(0xC5, 0x32, 0x3C);              /* VCM control */                                                   \
    ILI9341_CMD(0xC7, 0x91);                    /* VCM control2 */                                                  \
    ILI9341_CMD(0x36, (0x20 | 0x80 | 0x08));    /* Memory Access Control  (0x20|0x80|0x08) */                       \
    ILI9341_CMD(0xB1, 0x00, 0x10);              /* Frame Rate Control (1B=70, 1F=61, 10=119) */                     \
    ILI9341_CMD(0xB6, 0x0A, 0xA2);              /* Display Function Control */                                      \
    ILI9341_CMD(0xF6, 0x01, 0x30);                                                                               \
    ILI9341_CMD(0xF2, 0x00); /* 3Gamma Function Disable */                                                       \
    ILI9341_CMD(0x26, 0x01); /* Gamma curve selected */                                                          \
    ILI9341_CMD(0xE0, 0x0F, 0x31, 0x2B, 0x0C, 0x0E, 0x08, 0x4E, 0xF1, 0x37, 0x07, 0x10, 0x03, 0x0E, 0x09, 0x00); \
    ILI9341_CMD(0xE1, 0x00, 0x0E, 0x14, 0x03, 0x11, 0x07, 0x31, 0xC1, 0x48, 0x08, 0x0F, 0x0C, 0x31, 0x36, 0x0F);

// Input
// Refer to rg_input.h to see all available RG_KEY_* and RG_GAMEPAD_*_MAP types

#define RG_GAMEPAD_GPIO_MAP {\
    {RG_KEY_UP,     GPIO_NUM_41, GPIO_PULLUP_ONLY, 0},\
    {RG_KEY_DOWN,   GPIO_NUM_42, GPIO_PULLUP_ONLY, 0},\
    {RG_KEY_LEFT,   GPIO_NUM_43, GPIO_PULLUP_ONLY, 0},\
    {RG_KEY_RIGHT,  GPIO_NUM_44, GPIO_PULLUP_ONLY, 0},\
    {RG_KEY_SELECT, GPIO_NUM_45, GPIO_PULLUP_ONLY, 0},\
    {RG_KEY_START,  GPIO_NUM_46, GPIO_PULLUP_ONLY, 0},\
    {RG_KEY_A,      GPIO_NUM_16, GPIO_PULLUP_ONLY, 0},\
    {RG_KEY_B,      GPIO_NUM_15, GPIO_PULLUP_ONLY, 0},\
}


// Battery
#define RG_BATTERY_DRIVER           0
// #define RG_BATTERY_ADC_UNIT         ADC_UNIT_1
// #define RG_BATTERY_ADC_CHANNEL      ADC_CHANNEL_3
// #define RG_BATTERY_CALC_PERCENT(raw) (((raw) * 2.f - 3500.f) / (4200.f - 3500.f) * 100.f)
// #define RG_BATTERY_CALC_VOLTAGE(raw) ((raw) * 2.f * 0.001f)

// Status LED
#define RG_GPIO_LED                 GPIO_NUM_2

// I2C BUS
// #define RG_GPIO_I2C_SDA             GPIO_NUM_10
// #define RG_GPIO_I2C_SCL             GPIO_NUM_11

// SPI Display
#define RG_GPIO_LCD_MISO            GPIO_NUM_40
#define RG_GPIO_LCD_MOSI            GPIO_NUM_12
#define RG_GPIO_LCD_CLK             GPIO_NUM_48
#define RG_GPIO_LCD_CS              GPIO_NUM_4
#define RG_GPIO_LCD_DC              GPIO_NUM_47
// #define RG_GPIO_LCD_BCKL            GPIO_NUM_39 // RG_GPIO_SDSPI_CS
#define RG_GPIO_LCD_RST             GPIO_NUM_5

// SPI SD Card
#define RG_GPIO_SDSPI_MISO      GPIO_NUM_37
#define RG_GPIO_SDSPI_MOSI      GPIO_NUM_35
#define RG_GPIO_SDSPI_CS        GPIO_NUM_39
#define RG_GPIO_SDSPI_CLK       GPIO_NUM_36

// keep the old because it complains?
// #define RG_GPIO_SDSPI_CMD          GPIO_NUM_14
// #define RG_GPIO_SDSPI_CLK          GPIO_NUM_21
// #define RG_GPIO_SDSPI_D0           GPIO_NUM_17


// External I2S DAC
#define RG_GPIO_SND_I2S_BCK         38
#define RG_GPIO_SND_I2S_WS          13
#define RG_GPIO_SND_I2S_DATA        9
#define RG_GPIO_SND_AMP_ENABLE      18