#include <Input/Commands/MoveLeftCommand.h>

using namespace Core;

void MoveLeftCommand::execute(GameObjects::Pawn* actor) {
    actor->MoveLeft();
    Log::LogDebug("Move left");
}
