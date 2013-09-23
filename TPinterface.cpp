#include "TPinterface.h"
#include "LightingScene.h"
double pi = acos(-1.0);

TPinterface::TPinterface()
{
	testVar=0;
}


void TPinterface::processKeyboard(unsigned char key, int x, int y)
{
	// Uncomment below if you would like to process the default keys (e.g. 's' for snapshot, 'Esc' for exiting, ...)
	// CGFinterface::processKeyboard(key, x, y);
	switch(key)
	{
	case 'i':
		{


			((LightingScene *) scene)->robot->z+=(cos(((LightingScene *) scene)->robot->ang*pi/180));
			((LightingScene *) scene)->robot->x+=(sin(((LightingScene *) scene)->robot->ang*pi/180));
			break;
		}
	case 'k':
		{
			((LightingScene *) scene)->robot->z-=(cos(((LightingScene *) scene)->robot->ang*pi/180));
			((LightingScene *) scene)->robot->x-=(sin(((LightingScene *) scene)->robot->ang*pi/180));
			break;
		}
	case 'j':
		{
			((LightingScene *) scene)->robot->ang++;
			break;
		}
	case 'l':
		{
			((LightingScene *) scene)->robot->ang--;
			//((LightingScene *) scene)->toggleSomething();
			break;
		}
	}
}
int teste=1;
int texturas=1;
void TPinterface::initGUI()
{
	// Check CGFinterface.h and GLUI documentation for the types of controls available
	//GLUI_Panel *varPanel= addPanel("Group", 1);
	//addSpinnerToPanel(varPanel, "Val 1(interface)", 2, &testVar, 1);

	// You could also pass a reference to a variable from the scene class, if public
	//addSpinnerToPanel(varPanel, "Val 2(scene)", 2, &(((LightingScene*) scene)->sceneVar), 2);
	//addColumn ();
	GLUI_Panel *varLuz= addPanel("Luzes", 2);
	addCheckboxToPanel(varLuz, "Luz 1",&((LightingScene *) scene)->state1,NULL);
	addCheckboxToPanel(varLuz, "Luz 2",&((LightingScene *) scene)->state2,NULL);
	addCheckboxToPanel(varLuz, "Luz 3",&((LightingScene *) scene)->state3,NULL);
	addCheckboxToPanel(varLuz, "Luz 4",&((LightingScene *) scene)->state4,NULL);
	addColumn ();
	GLUI_Panel *varClock= addPanel("Relogio", 3);
	addStaticText("Relógio");
	addButton ("Pause/Start",1);
	addColumn ();
	GLUI_Panel *vartext= addPanel("Texturas",4);
	GLUI_Listbox *textvar =addListboxToPanel(vartext,"Texturas",&((LightingScene *) scene)->statetext,NULL);
	textvar->add_item (1, "Default");
	textvar->add_item (2, "Sky");
	textvar->add_item (3, "Space");
	textvar->set_int_val (3); 
	addColumn();
	GLUI_Panel *varwire= addPanel("Wireframe",5);
	GLUI_RadioGroup *group=addRadioGroupToPanel(varwire,&((LightingScene *) scene)->wire);
	addRadioButtonToGroup(group,"Normal");
	addRadioButtonToGroup(group,"Wireframe");
	addColumn();
}

void TPinterface::processGUI(GLUI_Control *ctrl)
{
	printf ("GUI control id: %d\n  ",ctrl->user_id);
	switch (ctrl->user_id)
	{
	case 1:
		{
			if(teste==1){
			((LightingScene *) scene)->state5=false;
			//printf ("New Val 2(scene): %d\n",((LightingScene*) scene)->sceneVar);
			teste=2;
			break;
			}
			if(teste==2){
			((LightingScene *) scene)->state5=true;
			teste=1;
			break;
			
			}
		}
	};
}

