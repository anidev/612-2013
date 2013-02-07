#include "Networkcom.h"

NetworkCom::NetworkCom() {
	NetworkTable* table=NetworkTable::GetTable("612");
	if(table!=NULL) {
		table->GetSubTable("Tracking");
		table->GetSubTable("Gunner");
		table->GetSubTable("Autonomous");
	}
}

NetworkCom::~NetworkCom() {
}
