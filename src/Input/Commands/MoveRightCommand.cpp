#include <Input/Commands/MoveRightCommand.h>

using namespace Core;

void MoveRightCommand::execute(GameObject* actor) {
    actor->MoveRight();
}

