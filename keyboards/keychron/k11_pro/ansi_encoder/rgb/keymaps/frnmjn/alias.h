#define NO		KC_NO
#define TRNS	KC_TRNS
#define SFT		KC_LSFT
#define ALT		KC_LALT
#define CTL		KC_LCTL
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

#define PUP		KC_PGUP
#define PDN		KC_PGDN
#define BT		BT_HST1

#define DTUP 	DT_UP 
#define DTDOWN 	DT_DOWN


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
#define TILD    ALGR(IT_IGRV)
#define GRV     ALGR(IT_QUOT)
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
