#include <Input/Commands/MoveLeftCommand.h>

using namespace Core;

void MoveLeftCommand::execute(GameObject* actor) {
    actor->MoveLeft();
}
