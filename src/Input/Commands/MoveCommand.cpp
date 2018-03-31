#include <Input/Commands/MoveCommand.h>

using namespace Core;

void MoveCommand::execute(GameObject* actor) {
    Log::LogInfo("Move command executes");
    actor->addPosition(5, 5);

}