#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <GL/gl.h>
#include <math.h>


/** DEFINITIONS **/

#define KG_WINDOW_TITLE                     "KbG Praktika - Xabier Lecumberri & Iker Ortiz"
#define KG_WINDOW_WIDTH                     960
#define KG_WINDOW_HEIGHT                    540
#define KG_WINDOW_X                         50
#define KG_WINDOW_Y                         50

#define KG_MSSG_SELECT_FILE                 "Idatz ezazu fitxategiaren path-a: "
#define KG_MSSG_FILENOTFOUND                "Fitxategi hori ez da existitzen!!"
#define KG_MSSG_INVALIDFILE                 "Arazoren bat egon da fitxategiarekin ..."
#define KG_MSSG_EMPTYFILE                   "Fitxategia utsik dago"
#define KG_MSSG_FILEREAD                    "Fitxategiaren irakurketa buruta"

#define KG_QUICK_LOAD                          "../Objektuak/al.obj"

#define KG_STEP_MOVE                        5.0f
#define KG_STEP_ROTATE                      10.0f
#define KG_STEP_ZOOM                        0.75
#define KG_STEP_CAMERA_ANGLE                5.0f

#define KG_ORTHO_X_MIN_INIT                -5
#define KG_ORTHO_X_MAX_INIT                 5
#define KG_ORTHO_Y_MIN_INIT                -5
#define KG_ORTHO_Y_MAX_INIT                 5
#define KG_ORTHO_Z_MIN_INIT                -100
#define KG_ORTHO_Z_MAX_INIT                 10000

#define KG_COL_BACK_R                       0.73f
#define KG_COL_BACK_G                       0.73f
#define KG_COL_BACK_B                       0.73f
#define KG_COL_BACK_A                       0.00f

#define KG_COL_GRID_R                       0.40f
#define KG_COL_GRID_G                       0.40f
#define KG_COL_GRID_B                       0.40f

#define KG_COL_TEXT_R                       0.00f
#define KG_COL_TEXT_G                       0.00f
#define KG_COL_TEXT_B                       0.00f

#define KG_POS_TEXT_X                      -0.99f
#define KG_POS_TEXT_Y                      -0.50f

#define KG_COL_SELECTED_R                   0.00f
#define KG_COL_SELECTED_G                   0.84f
#define KG_COL_SELECTED_B                   0.00f

#define KG_COL_NONSELECTED_R                1.00f
#define KG_COL_NONSELECTED_G                1.00f
#define KG_COL_NONSELECTED_B                1.00f

#define KG_COL_X_AXIS_R                     1.0f
#define KG_COL_X_AXIS_G                     0.0f
#define KG_COL_X_AXIS_B                     0.0f

#define KG_COL_Y_AXIS_R                     0.0f
#define KG_COL_Y_AXIS_G                     1.0f
#define KG_COL_Y_AXIS_B                     0.0f

#define KG_COL_Z_AXIS_R                     0.0f
#define KG_COL_Z_AXIS_G                     0.0f
#define KG_COL_Z_AXIS_B                     1.0f

#define KG_MAX_DOUBLE                       1000

#define PI                                  3.141592653589793f

#define KG_MODE_GLOBAL                         0
#define KG_MODE_LOKAL                          1

#define KG_MODE_DEFAULT                       -1
#define KG_MODE_TRANS							0
#define KG_MODE_BIRAK							1
#define KG_MODE_ESKAL							2
#define KG_MODE_ISLAP                          3

#define KG_TRANS_ABIAD                      0.25
#define KG_BIRAK_ANG                        PI/16
#define KG_ESKAL_HAND                       1.25f
#define KG_ESKAL_TXIK                       1/KG_ESKAL_HAND

#define GLUT_CTRL                           114


/** STRUCTURES **/

/****************************
 * Structure to store the   *
 * coordinates of 3D points *
 ****************************/
typedef struct {
    GLdouble x, y, z;
} point3;

/*****************************
 * Structure to store the    *
 * coordinates of 3D vectors *
 *****************************/
typedef struct {
    GLdouble x, y, z;
} vector3;

/****************************
 * Structure to store the   *
 * colors in RGB mode       *
 ****************************/
typedef struct {
    GLfloat r, g, b;
} color3;

/****************************
 * Structure to store       *
 * objects' vertices         *
 ****************************/
typedef struct {
    point3 coord;                       /* coordinates,x, y, z */
    GLint num_faces;                    /* number of faces that share this vertex */
} vertex;

/****************************
 * Structure to store       *
 * objects' faces or        *
 * polygons                 *
 ****************************/
typedef struct {
    GLint num_vertices;                 /* number of vertices in the face */
    GLint *vertex_table;                /* table with the index of each vertex */
} face;

/****************************
 * Structure to store a     *
 * pile of transformation   *
 * matrixes                 *
 ****************************/

typedef struct{
    GLdouble *matrix;
    struct pila *next;
} pila;

/****************************
 * Structure to store a     *
 * pile of 3D objects       *
 ****************************/
struct object3d{
    char *izena;
    GLint num_vertices;                 /* number of vertices in the object*/
    vertex *vertex_table;               /* table of vertices */
    GLint num_faces;                    /* number of faces in the object */
    face *face_table;                   /* table of faces */
    point3 min;                         /* coordinates' lower bounds */
    point3 max;                         /* coordinates' bigger bounds */
	pila *pila_z;					/* Egindako aldaketak */
    pila *pila_y;			    /* Desegindako aldaketak */
    struct object3d *next;              /* next element in the pile of objects */
};

typedef struct object3d object3d;



#endif // DEFINITIONS_H
