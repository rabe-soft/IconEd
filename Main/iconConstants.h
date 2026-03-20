/******************************************************************************
 *
 * PROJECT:	Icon Editor	(GOC Version)
 *  FILE:       iconConstant.h
 *
 *  AUTHOR:     Steve Yegge, Sep 2, 1992
 *
 *  REVISION HISTORY:
 *      Name    Date        Description
 *      ----    ----        -----------
 *      stevey  9/2/92      constants 'n' stuff for icon editor
 *	RainerB 7/18/2025   Ported to GOC
 *
 *
 * DESCRIPTION:	Constants and structures for different purposes
 *
 *
 *****************************************************************************/
#ifndef _ICON_CONSTANTS_H
#define _ICON_CONSTANTS_H

#include "token.h"

/*-----------------------------------------------------------------------------
 *      General-purpose constants
 *---------------------------------------------------------------------------*/


#define NO_CURRENT_ISET              -1
#define NO_CURRENT_ICON            -1

#define VIS_ISET_FONT_SIZE           9
#define VIS_ISET_FONT_ID             FID_UNIVERSITY
#define VIS_ISET_MINIMUM_WIDTH       64  /* bitmap and/or text */
#define VIS_ISET_MINIMUM_HEIGHT      30  /* bitmap only */
#define VIS_ISET_SPACER              3   /* between bitmap & text */
#define VIS_ISET_TEXT_HEIGHT         (VIS_ISET_FONT_SIZE + 3)  /* more or less */

#define DEFAULT_FATBITS_SIZE		8

#define VC_WHITE	C_WHITE
#define VC_SILVER	29	/* Index color very light gray */
#define VC_GRAY		C_LIGHT_GRAY
#define VC_ORANGE	232
#define VC_YELLOW	254
#define VC_BLUE		135
#define VC_GREEN	181
#define VC_SAND		247

#define COLOR_DARK_SILVER	28	/* Index color light gray */
#define COLOR_DARK_SILVER_2	27	/* Index color darker light gray */

#define DEFAULT_VIEW_COLOR	VC_SILVER

#define IC_DITHER_IMAGE		(IC_CUSTOM_START+1)
#define IC_RESIZE_IMAGE		(IC_CUSTOM_START+2)
#define IC_STILL_USE_IMAGE	(IC_CUSTOM_START+3)
#define IC_SELECT_GEODE		(IC_CUSTOM_START+4)
#define IC_SELECT_PATH		(IC_CUSTOM_START+5)

/*-----------------------------------------------------------------------------
 *      Icon parameters and bitmap sizes
 *---------------------------------------------------------------------------*/

/*
 *  IconParameters is a bitflags record that is used for BooleanGroups
 *  to select initial properties and to initialize icons.
 *  The numerical values determine the order in which the icons are created
 *  and appear in the icon list.
 */
typedef enum {

    /*
     * 64x40, SVGA file icons - display size: standard
     * actually not used for file icons, but for preferences module icons
     */
    IP_STANDARD_SVGA_FILE_256 	= 0x01,		/* 256 colors */
    IP_STANDARD_SVGA_FILE 	= 0x02,		/* 16 colors */
    IP_STANDARD_SVGA_FILE_MONO 	= 0x04,		/* VGA mono */

    /* 64x18 */
    IP_CGA_PREF_MODULE 		= 0x08,		/* CGA mono, very squished */

    /*
     * 48x30, VGA file icons - display size: standard
     */
    IP_STANDARD_VGA_FILE_256 	= 0x10,		/* 256 colors */
    IP_STANDARD_VGA_FILE 	= 0x20,		/* 16 colors */
    IP_STANDARD_MCGA_FILE	= 0x40,		/* monochrome */

    /*
     * 32x20, Tiny screen file icons - display size: tiny
     */
    IP_TINY_COLOR_FILE_256	= 0x80,		/* 256 colors */
    IP_TINY_COLOR_FILE		= 0x100,	/* 16 colors */
    IP_TINY_MONO_FILE		= 0x200,	/* monochrome */

    /* 48x14, CGA file icon - display size: standard, aspect: very squished
     */
    IP_STANDARD_CGA_FILE 	= 0x400,	/* mono CGA */


    /* 15x15, Standard screen tools are not available, because we have only
     * 16 bit :-( -- But there is no probem because the default file tool icons
     * for the the Express menu are usualay marked as TINY (even if STANDARD
     * works too)
     */

    /*
     * 15x15, Tiny screen tools icons - display size: tiny
     */

    IP_TINY_COLOR_TOOL_256	= 0x800,	/* 256 colors */
    IP_TINY_COLOR_TOOL		= 0x1000,	/* 16 colors */
    IP_TINY_MONO_TOOL		= 0x2000,	/* monochrome */


    /*
     * 15x10, CGA tool icon - display size: standard, aspect very squshed
     */
    IP_STANDARD_CGA_TOOL	= 0x4000,	/* 15x10, mono CGA */

    /*
     * Pointer images have a special format
     *		µµ möglichrweise its es gar nicht sinnvioll, den Wert hier zu listen
     */
    IP_PTR_IMAGE		= 0x8000,	/* 16x16, Pointer Image */


    /* Note that EGA screens are not longer supported by the system.
     * Use standard (VGA) screen instead.
     */

} IconParameters;



/*
 * File icon sizes
 * Note that usually the values are used, not the symbolic constants.
 * This significantly improves the readability of the program.
 */
#define SVGA_COLOR_FILE_MONIKER_HEIGHT        40
#define SVGA_COLOR_FILE_MONIKER_WIDTH         64
#define STANDARD_COLOR_FILE_MONIKER_HEIGHT    30
#define STANDARD_COLOR_FILE_MONIKER_WIDTH     48
#define STANDARD_MONO_FILE_MONIKER_HEIGHT     30
#define STANDARD_MONO_FILE_MONIKER_WIDTH      48
#define STANDARD_CGA_FILE_MONIKER_HEIGHT      14
#define STANDARD_CGA_FILE_MONIKER_WIDTH       48
#define TINY_COLOR_FILE_MONIKER_HEIGHT        20
#define TINY_COLOR_FILE_MONIKER_WIDTH         32
#define TINY_MONO_FILE_MONIKER_HEIGHT         20
#define TINY_MONO_FILE_MONIKER_WIDTH          32

/*
 * Tool icon sizes
 * Note that usually the values are used, not the symbolic constants.
 * This significantly improves the readability of the program.
 */
#define SVGA_COLOR_TOOL_MONIKER_HEIGHT        15
#define SVGA_COLOR_TOOL_MONIKER_WIDTH         15
#define STANDARD_COLOR_TOOL_MONIKER_HEIGHT    15
#define STANDARD_COLOR_TOOL_MONIKER_WIDTH     15
#define STANDARD_MONO_TOOL_MONIKER_HEIGHT     15
#define STANDARD_MONO_TOOL_MONIKER_WIDTH      15
#define STANDARD_CGA_TOOL_MONIKER_HEIGHT      10
#define STANDARD_CGA_TOOL_MONIKER_WIDTH       15

/* Mouse cursor sizes */
#define STANDARD_PTR_IMAGE_WIDTH              16
#define STANDARD_PTR_IMAGE_HEIGHT             16


/*-----------------------------------------------------------------------------
 *      UI initial values
 *---------------------------------------------------------------------------*/

/* Defaults for Icon Preview Dialog */
#define DEFAULT_ON_COLOR_1		C_LIGHT_BLUE
#define DEFAULT_ON_COLOR_2		C_LIGHT_BLUE
#define DEFAULT_OFF_COLOR_1		C_LIGHT_GRAY
#define DEFAULT_OFF_COLOR_2		C_LIGHT_GRAY
#define DEFAULT_PREVIEW_OBJECT		PGIO_TRIGGER


/*-----------------------------------------------------------------------------
 *      Sizes of the different Views
 *---------------------------------------------------------------------------*/

    /*
     * When a View switches from not scrollable to scrollable, we
     * need some pixels more to show the scrollers.
     * In reality, this depends on the settings in GEOS.INI. To
     * simplify things, we use a (somewhat large) fixed value.
     */
#define SPACE_FOR_SCROLLERS		24

    /*
     * IconDBView has a fixed witdh an a varibale height
     */
#define VIEWER_MARGIN                   10
#define VIEWER_HORIZONTAL_CHILD_SPACING 15
#define VIEWER_VERTICAL_CHILD_SPACING   10

#define	VIEWER_VIEW_FIXED_WIDTH	\	/* three standard icons plus margins plus room for scollbar */
	(3*VIS_ISET_MINIMUM_WIDTH + 2*VIEWER_HORIZONTAL_CHILD_SPACING \
	 + 2*VIEWER_MARGIN + SPACE_FOR_SCROLLERS)
#define	VIEWER_VIEW_MIN_HEIGHT		(128)
#define	VIEWER_VIEW_MAX_HEIGHT		(0x3FE)	/* no limit. max allowed is 0x3FF */

    /*
     * FatbitsView has a variable size
     */
#define FATBITS_MIN_WIDTH	(2*VIS_ISET_MINIMUM_WIDTH)
#define FATBITS_MIN_HEIGHT	(2*VIS_ISET_MINIMUM_WIDTH)
    /*
     * LivePreviewView has an fixed size
     */
#define LIVE_PREVIEW_MARGIN	3
#define LIVE_PREVIEW_WIDTH	(VIS_ISET_MINIMUM_WIDTH + 2*LIVE_PREVIEW_MARGIN + SPACE_FOR_SCROLLERS)
#define LIVE_PREVIEW_HEIGHT	LIVE_PREVIEW_WIDTH

    /*
     * IconListView has a variable width and a fixed heigt
     */
#define ICON_LIST_MARGIN	8
#define ICON_LIST_WIDTH	(VIS_ISET_MINIMUM_WIDTH + 2*ICON_LIST_MARGIN + SPACE_FOR_SCROLLERS)
#define ICON_LIST_HEIGHT	(VIS_ISET_MINIMUM_WIDTH + 2*ICON_LIST_MARGIN)
#define ICON_LIST_HORIZONTAL_CHILD_SPACING 8
#define ICON_LIST_VERTICAL_CHILD_SPACING   8

    /*
     * ImportPreviewView has a fixed size
     */
#define IMPORT_PREVIEW_MARGIN	4
#define IMPORT_PREVIEW_WIDTH	(128 + 2*LIVE_PREVIEW_MARGIN + SPACE_FOR_SCROLLERS)
#define IMPORT_PREVIEW_HEIGHT	IMPORT_PREVIEW_WIDTH

    /*
     * CustomColorsIndexView has a fixed size
     */
#define MORE_COLORS_MARGIN		3
#define MORE_COLORS_TOP_BLOCK_SIZE	16
#define MORE_COLORS_BOTTOM_BLOCK_SIZE	14
#define MORE_COLORS_SPACER	(MORE_COLORS_BOTTOM_BLOCK_SIZE/2)
#define MORE_COLORS_WIDTH	(24*MORE_COLORS_BOTTOM_BLOCK_SIZE + 2*MORE_COLORS_MARGIN)
#define MORE_COLORS_HEIGHT	(MORE_COLORS_TOP_BLOCK_SIZE \
				+ 10*MORE_COLORS_BOTTOM_BLOCK_SIZE \
				+ MORE_COLORS_SPACER\
				+ 2*MORE_COLORS_MARGIN)

    /*
     * CCCurrentColorView has a fixed size
     */
#define SINGLE_COLOR_VIEW_WIDTH	128
#define SINGLE_COLOR_VIEW_HEIGHT	50

    /*
     * HSV views have a fixed size
     */
#define HSV_BAR_VIEW_WIDTH		256
#define HSV_BAR_VIEW_HEIGHT		12


/*-----------------------------------------------------------------------------
 *	ISetMenu and Icon menu
 *---------------------------------------------------------------------------*/

/* New icon set creation type */
typedef enum {
    NEW_FILE_ISET,
    NEW_TOOL_ISET,
    NEW_PTR_ISET,
    NEW_PREF_MODULE_ISET,	// <-- only required if ENABLE_PREF_MODULE_ISET is defined
    NEW_CUSTOM_ISET
} CreateNewISetType;


/* Transformation operations */
typedef enum {
    ITT_FLIP_HORIZONTALLY = 0x100,
    ITT_FLIP_VERTICALLY,
    ITT_ROTATE_90,
    ITT_ROTATE_180,
    ITT_ROTATE_270
} IconTransformType;

#define DEFAULT_NEW_ISET_FILE_ICONS ( IP_STANDARD_VGA_FILE  	\
		| IP_STANDARD_MCGA_FILE | IP_STANDARD_CGA_FILE)

#define DEFAULT_NEW_ISET_TOOL_ICONS ( IP_TINY_COLOR_TOOL 	\
		| IP_TINY_MONO_TOOL | IP_STANDARD_CGA_TOOL)

#define DEFAULT_NEW_ISET_ICONS (DEFAULT_NEW_ISET_FILE_ICONS | DEFAULT_NEW_ISET_TOOL_ICONS)

#define DEFAULT_NEW_TOOL_ICONS (IP_TINY_COLOR_TOOL \
		| IP_TINY_MONO_TOOL | IP_STANDARD_CGA_TOOL )


/*
 * Custom Tools must also have its own bit in IconParameters flagbits record.
 * The only condition is, it must not equal to any of the _TOOL bits, or
 * creating custom tool icons will not work properly.
 * IP_xx_TOOL_ bits starts with 0x800.
 * Therefore we use 0x01 and 0x02.
 */

#define IP_CUSTOM_COLOR_TOOL	0x01 	/* user defined colored tool*/
#define IP_CUSTOM_MONO_TOOL	0x02 	/* user defined monochrome tool */


#define MAX_ICON_WIDTH             1024
#define MAX_ICON_HEIGHT            1024
#define MAX_SAFE_MONIKER_SIZE        8192    /* 8k data blocks */

#define	MAX_ICONS		32	/* Each icon set can have max. 32 icons.
					 * See also TooManyIconsText if you change
					 * this value */
#define MAX_SEARCH_RESULT_ICONS	100	/* We can find max 100 icons for each token
					 * in the token database. This is much more that
					 * our MAX_ICONS if anyone has broken this limit.
					 * Also update TooManyIconsInToken if you change
					 * this value. */

/*-----------------------------------------------------------------------------
 *      Token database import / export / write source code
 *---------------------------------------------------------------------------*/

    /*
     * Import from token database
     */
#define	TOKEN_LIST_TEXT_SIZE	10
#define	TOKEN_LIST_ITEM_WIDTH	(64+4)
#define	TOKEN_LIST_MONIKER_HEIGHT (40+10)
	/* ^--- SuperVGA size: 64x40 plus x */
#define	TOKEN_LIST_ITEM_HEIGHT	(TOKEN_LIST_MONIKER_HEIGHT + 2*TOKEN_LIST_TEXT_SIZE + 4)
#define	TOKEN_SCROLLBAR_WIDTH	14
	/* ^--- this value is estimated. For an exact value we have to read a value (which) from ini file? */

#define	ICON_LIST_ITEM_WIDTH	(64+4)
#define	ICON_LIST_ITEM_HEIGHT	(40+4)

    /*
     * Export to token database and write to source code
     */
#define EXPORT_TOKEN_PREVIEW_WIDTH	(64 + 15)
#define EXPORT_TOKEN_PREVIEW_HEIGHT	(40 + 10)
	/* ^--- SuperVGA size: 64x40 plus x */

#define GET_TOKEN_FROM_ID	1
#define GET_TOKEN_FROM_GEODE	2

#define COMPRESS_ICON_NEVER	1
#define COMPRESS_ICON_ALWAYS	2
#define COMPRESS_ICON_AUTO	3
#define ICON_COMPRESS_BITS	0x0F	/* filter out COMPRES_ICON_xx bits */

#define	WRITE_TRANSPARENCY_MASK	0x100
#define	USE_FILL_BITMAP_FOR_MONO 0x200	/* Optimize transparency for monochrome bitmaps by removing
					 * the transparency layer and use GrFillBitmap (which draws
					 * monochrome bitmaps transparent) instead of GrDrawBitmap */

					/* This flag is currently always set, there is no UI to
					 * switch it of (this may confuse the user), but the code
					 * is prepared for this */
    /*
     * Structures for token import/export
     */

/* Structure for searching monikers/icons when importing tokens */
typedef struct {	/* All data needed for TokenLoadMonikerBlock() */
    DisplayType		displayType;	/* DS_xx, DAR_xx, DCxx */
    VisMonikerSearchFlags searchFlags;	/* VMS_xx, VMSF_GSTRING */
    } MonikerFoundStruct;

/*
 * Structure that holds all required information about an icon for import
 */
typedef struct {
    /* Common moniker information */
    Boolean		isGString;	/* ... or a text moniker */
    DisplaySize		displaySize; 	/* DS_STANDRAD .. */
    VMStyle		iconStyle;	/* VMS_ICON ... */
    DisplayAspectRatio	aspect;		/* DAR_NORMAL ... */
    DisplayClass	displayClass;	/* DC_COLOR_4 ... */
    word		width, height;	/* dimensions, read from VisMoniker structure
    					 * is isGString == FALSE, width is set to
    					 * the number of charachtes and height is (-1) */

    /* Special bitmap information from GString analyse */
    Boolean		bitmapFound;	/* if not, we assume a simple gstring and
    					   the next fields are invalid */
    word		bitmapOffset;	/* position of bitmap header (Bitmap or CBitmap strcuture)
    					   counted from start of the VisMoniker structure */
    word		bitmapDataSize;	/* size of bitmap data, including the header */
    GStringElement	opCode;		/* GString operation code for drawing bitmap,
    					 * e.g. GR_DRAW_BITMAP_CP */
    BMType		bmFormat;	/* color depth, mask, palette
    					 * if bitmapFound == FALSE, the field is set to
    					 * BMT_MASK | BMF_24BIT */
    BMCompact		compact;	/* BMC_UNCOMPACTED, BMC_PACKBITS, BMC_USER_DEFINED */


} MonikerAnalyseResult;


/* Structure for brute force moniker scanning */
typedef struct {
    MonikerFoundStruct	foundInfo;
    TokenMonikerInfo 	monikerInfo;
    } MonikerSearchResult;

/* Structure to simple access List of tokens. 6 Bytes header, followed by an GeodeToken array */
typedef struct {
    word	tokenCount;	// .. in the list
    word	firstIndex;	// .. to display in TokenList
    word	tokensToShow;	// .. in the tokenList
    GeodeToken	token[];	// array of GeodeToken structs
    				// sorted by manufacturer ID
    } TokenListStruct;


/*
 * Possible return values for
 *	- ToolExpTokenCheckReady
 *	- ToolWriteSourceCheckReady
 * see routines for details
 */

#define TOKEN_READY_FOR_EXPORT			0
#define TOKEN_READY_IF_MINIMZE			1
#define TOKEN_READY_IF_COMPRESS			2

#define TOKEN_FIRST_NOT_READY_VALUE 			0x10
#define TOKEN_NOT_READY_BECAUSE_SIZE		TOKEN_FIRST_NOT_READY_VALUE
#define TOKEN_NOT_READY_BECAUSE_PROPERTIES	0x11	/* ToolExpTokenCheckReady only */

#define TOKEN_RGB_WARNING			0x100
#define TOKEN_EMPTY_WARNING			0x200
#define TOKEN_PROPERTIES_WARNING		0x400	/* ToolWriteSourceCheckReady only */
#define TOKEN_ICON_NAMES_WARNING		0x800	/* ToolWriteSourceCheckReady only */

#define TOKEN_WARNING_BITS	(0xF00)
#define TOKEN_STATUS_BITS	(0xFF)


/*-----------------------------------------------------------------------------
 *      µµ Noch ohne Gruppe
 *---------------------------------------------------------------------------*/

typedef struct {
    Rectangle	CIRS_rect;      // rubberband
    word 	CIRS_flags;     // control & shift key info	// µµ benutzt? --> löschen?

    //word 	CIRS_chunk;     // callee's object chunk handle
    //byte 	CIRS_unused;    // padding to make structure size even
// µµ ubenutzt? --> kann gelöscht werden
} CheckInRectangleStruct;


/*-----------------------------------------------------------------------------
 *      Identifiers for different items
 *---------------------------------------------------------------------------*/

/*
 * Standard Drawing positions for drawing on bitmap into another
 * defined as value from 101 to 109
 */
typedef enum {
    DRAW_AT_TOP_LEFT = 101,	// top left corner
    DRAW_AT_TOP_MIDDLE,		// middle on top
    DRAW_AT_TOP_RIGHT,		// upper right corner
    DRAW_AT_MIDDLE_LEFT,	// middle left
    DRAW_AT_CENTER,		// centered
    DRAW_AT_MIDDLE_RIGHT,	// middle right
    DRAW_AT_BOTTOM_LEFT,	// bottom left corner
    DRAW_AT_BOTTOM_MIDDLE,	// middle on bottom
    DRAW_AT_BOTTOM_RIGHT	// bottom right corner
} StandardDrawingPostion;

typedef enum {
    DRAW_RELATIVE_TO_SELECTION	= 1,
    DRAW_LIMITED_TO_SELECTION	= 2
} DrawToSelectionOptions;

/*
 * ActionData for Shift-Image Triggers
 */
typedef enum {
    SHIFT_TO_TOP_LEFT = 1,	// top left corner
    SHIFT_TO_TOP,		// upwards
    SHIFT_TO_TOP_RIGHT,		// upper right corner
    SHIFT_TO_LEFT,		// to left
    SHIFT_TO_RIGHT,		// to right
    SHIFT_TO_BOTTOM_LEFT,	// bottom left corner
    SHIFT_TO_BOTTOM,		// downwards
    SHIFT_TO_BOTTOM_RIGHT	// bottom right corner
} ShiftDirection;


/*
 * Edit mask control box idenfifiers - they are equal to the colors to use
 */
#define EMM_MAKE_TRANSPARENT	C_WHITE
#define EMM_MAKE_OPAQUE		C_BLACK

/*-----------------------------------------------------------------------------
 *      Options Records (bit fields)
 *---------------------------------------------------------------------------*/

typedef WordFlags  IconOptions;
    #define IO_SHOW_DATABASE	1
    #define IO_SHOW_FATBITS	2
    #define IO_SHOW_ICON	4
    #define IO_CONFIRM_DELETE	8
    #define IO_SELECT_ON_SINGLE_CLICK	0x10
    #define IO_COLORED_ICON_LIST	0x20
    #define IO_BACKGROUND_PATTERN	0x40	/* currently unused, but preserved for the
    						 * case that ENABLE_BACKGROUND_PATTERN
    						 * becomes re-enabled */
    #define IO_ALLOW_OVERSIZED_ICONS	0x80

    #define DEFAULT_ISET_OPTIONS (IO_SHOW_ICON | IO_SHOW_FATBITS \
	                       | IO_SHOW_DATABASE | IO_CONFIRM_DELETE \
	                       | IO_SELECT_ON_SINGLE_CLICK)
    #define DEFAULT_EDIT_ON_SINGLE_CLICK	((DEFAULT_ISET_OPTIONS & IO_SELECT_ON_SINGLE_CLICK) ? TRUE : FALSE)
    		/* MUST be true if IO_SELECT_ON_SINGLE_CLICK is listed in
    		 * DEFAULT_ISET_OPTIONS and MUST be FALSE if not */
/*
typedef WordFlags FormatOptions;	// µµ used? ->rename to Icon~
    #define FO_FLOATING_ICONS	1

*/
typedef WordFlags WriteToFileOptions;
    #define WTFO_WRITE_MASK	1
    #define WTFO_COMPACT_BITMAP 2


#define IE_INI_CATEGORY		"IconEd"
#define IE_INI_OPTIONS_KEY	"options"
#define IE_INI_FATBITS_KEY	"pixelSize"
#define IE_INI_VIEW_COLOR_KEY	"viewColor"
#define IE_INI_PATH_KEY		"path"

#define IE_FULL_PATH_BUFFER_SIZE	(PATH_BUFFER_SIZE + 10)

/*-----------------------------------------------------------------------------
 *      Write source dialog GenItem identifiers
 *---------------------------------------------------------------------------*/
typedef WordFlags WriteSourceIconType;
    #define WSIT_CURRENT_ICON	 	1
    #define WSIT_SELECTED_ICONS		2
    #define WSIT_ALL_ICONS		3

typedef WordFlags WriteSourceLanguageType;
    #define WSLT_GOC		1
    #define WSLT_ASM		2

typedef WordFlags WriteSourceHeaderType;
    #define WSHT_VIS_MONIKER	1
    #define WSHT_BITMAP		2
    #define WSHT_PTR_IMAGE	3


/*-----------------------------------------------------------------------------
 *      Constants
 *---------------------------------------------------------------------------*/
@if 0
/
/*-----------------------------------------------------------------------------
 *      Fatal Errors
 *---------------------------------------------------------------------------*/
typedef enum {
    CORRUPTED_ISET_DATABASE,
    ILLEGAL_REQUESTED_ICON_NUMER,
    BAD_DI_IN_EXTRACT_ISET_FROM_CHAIN,
    CANT_FLIP_BITMAP_OF_HEIGHT_ZERO
} FatalErrors;

@endif

@if 0

#define STANDARD_ISET_DPI            72




/*-----------------------------------------------------------------------------
 *      Constants for initializing GenValues in the application
 *---------------------------------------------------------------------------*/
#define DEFAULT_CUSTOM_WIDTH         48
#define DEFAULT_CUSTOM_HEIGHT        30
#define DEFAULT_RESIZE_WIDTH         48
#define DEFAULT_RESIZE_HEIGHT        30

/*-----------------------------------------------------------------------------
 *      Enumerations & Records
 *---------------------------------------------------------------------------*/





/* Color object color flags */
typedef struct {
    unsigned COCTS_ON_ONE   :1; /* sets first selected color */
    unsigned COCTS_ON_TWO   :1; /* sets second selected color */
    unsigned COCTS_OFF_ONE  :1; /* sets first unselected color */
    unsigned COCTS_OFF_TWO  :1; /* sets second unselected color */
} ColorObjectColorToSet;

/* Change icon set source */
typedef enum {
    CIST_FILE_SELECTOR,
    CIST_TOKEN_CHARS
} ChangeIconSourceType;

/* Write source errors */
typedef enum {
    WSE_NO_ERROR,
    WSE_BAD_FILENAME,
    WSE_FILE_CREATE,
    WSE_FILE_WRITE,
    WSE_INVALID_IMAGE
} WriteSourceErrors;

/*-----------------------------------------------------------------------------
 *      Transform enums
 *---------------------------------------------------------------------------*/
typedef enum { TDT_SOURCE_ICON, TDT_DEST_ICON } TransformDisplayType;
typedef enum { RFOT_SCALE_BITMAP, RFOT_KEEP_BITMAP } ResizeFormatOptionsType;

/*-----------------------------------------------------------------------------
 *      Other structures
 *---------------------------------------------------------------------------*/
typedef struct {
    uint16_t HB_block;   /* vm block handle of 1st block */
    void*    HB_handle;  /* vm file handle */
} HBitmap;

typedef struct {
    unsigned TBT_GROUP1 :1;
    unsigned TBT_GROUP2 :1;
} TitleBarTriggers;


@endif

#endif 	/* _ICON_CONSTANTS_H */

