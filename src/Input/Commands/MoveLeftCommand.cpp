#include <Input/Commands/MoveLeftCommand.h>

using namespace Core;

void MoveLeftCommand::execute(GameObjects::Pawn* actor) {
    actor->MoveLeft();
}
