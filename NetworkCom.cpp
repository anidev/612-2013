#include "Networkcom.h"

NetworkCom::NetworkCom() {
	NetworkTable* table=NetworkTable::GetTable("612");
	if(table!=NULL) {
		Tracking = table->GetSubTable("Tracking");
		Gunner = table->GetSubTable("Gunner");
		Autonomous = table->GetSubTable("Autonomous");
	}
}

NetworkCom::~NetworkCom() {
}
