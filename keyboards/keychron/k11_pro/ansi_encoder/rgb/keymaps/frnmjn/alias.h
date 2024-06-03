#define NO		KC_NO
#define TRNS	KC_TRNS
#define SFT		KC_LSFT
#define ALT		KC_LALT
#define CTL		KC_LCTL
#define CMD		KC_LCMD
#define GUI		KC_LGUI
#define ENT		KC_ENT
#define ESC		KC_ESC
#define HOME	KC_HOME
#define END		KC_END
#define SPC		KC_SPC
#define BSPC	KC_BSPC
#define DEL		KC_DEL
#define TAB		KC_TAB
#define LEFT 	KC_LEFT
#define UP		KC_UP
#define DOWN	KC_DOWN
#define RIGHT	KC_RIGHT

#define BT		BT_HST1

// Left-hand home row mods
#define HR_A  	LGUI_T(KC_A)
#define HR_S  	LALT_T(KC_S)
#define HR_D  	LCTL_T(KC_D)
#define HR_F  	LSFT_T(KC_F)

// Right-hand home row mods
#define HR_J  	RSFT_T(KC_J)
#define HR_K  	RCTL_T(KC_K)
#define HR_L  	LALT_T(KC_L)
#define HR_SCLN RGUI_T(KC_SCLN)


#define TD_F	TD(TD__F)
#define TD_C	TD(TD__C)
#define TD_D	TD(TD__D)
#define TD_S	TD(TD__S)
#define TD_RB	TD(TD__RB)
#define TD_SB	TD(TD__SB)
#define TD_CB	TD(TD__CB)
#define TD_E	TD(TD__E)
#define TD_SCLN	TD(TD__SCLN)
#define TD_SLSH	TD(TD__SLSH)
#define TD_COMM	TD(TD__COMM)
#define TD_DOT	TD(TD__DOT)

#define GONOR	LT(NOR, SPC)
#define GOSYM	MO(SYM)
#define GONUM	MO(NUM)

#define LEAD 	QK_LEAD

#define COMM 	IT_COMM 
#define DOT 	IT_DOT 
#define SLSH 	IT_SLSH
#define SCLN 	IT_SCLN 
#define QUOT 	IT_QUOT 
#define DQT     IT_DQUO
#define BSLS 	IT_BSLS 
#define SLS     IT_SLSH
#define AST 	IT_ASTR
#define MINS    IT_MINS
#define PLUS    IT_PLUS
#define EQL 	IT_EQL 
#define UNDS    IT_UNDS
#define AMPR    IT_AMPR
#define HASH    IT_HASH
#define TILD    IT_TILD
#define GRV     IT_GRV
#define PIPE	IT_PIPE
#define DLR     IT_DLR
#define EXLM    IT_EXLM
#define ASTR    IT_ASTR
#define AT		IT_AT
#define PERC    IT_PERC
#define CIRC	IT_CIRC

enum layers {
	 INS,
	 NOR,
	 SYM,
	 NUM,
	 OTH,
};
