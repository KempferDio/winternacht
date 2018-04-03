#include <Input/Commands/MoveRightCommand.h>

using namespace Core;

void MoveRightCommand::execute(GameObjects::Pawn* actor) {
    actor->MoveRight();
    Log::LogDebug("Move right");
}

