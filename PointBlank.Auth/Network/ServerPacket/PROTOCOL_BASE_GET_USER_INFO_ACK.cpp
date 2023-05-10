#include <Network/ServerPacket/PROTOCOL_BASE_GET_USER_INFO_ACK.hpp>
#include <Protocol/Acknowledge.hpp>
#include <Data/Model/Account.hpp>

PROTOCOL_BASE_GET_USER_INFO_ACK::PROTOCOL_BASE_GET_USER_INFO_ACK(Account* pAccount)
: AckPacketInterface(eProtocolPacketAck::BASE_GET_USER_INFO_ACK, 0), m_pAccount(pAccount) {
    AckPacketInterface::Reserve(this->GetMemoryUsage());

    Write<std::uint16_t>(0);
    Write<std::uint32_t>(pAccount ? 0U : 2147483648U);
    if (!pAccount)
        return;

        
    /* 
      this.writeH((short) 0);
      this.writeD(this.Error);
      if (this.Error != 0U)
        return;
      this.writeC((byte) this.Player.Characters.Count);
      this.writeH((short) 210);
      this.writeC((byte) QuickStartXml.QucikStarts.Count);
      for (int index = 0; index < QuickStartXml.QucikStarts.Count; ++index)
      {
        QuickStart qucikStart = QuickStartXml.QucikStarts[index];
        this.writeC((byte) qucikStart.MapId);
        this.writeC((byte) qucikStart.Rule);
        this.writeC((byte) qucikStart.StageOptions);
        this.writeC((byte) qucikStart.Type);
      }
      this.writeB(new byte[33]);
      this.writeC((byte) 4);
      this.writeD(0);
      this.writeD(0);
      this.writeD(0);
      this.writeD(0);
      this.writeD(0);
      this.writeD(this.Player._titles.Slots);
      this.writeC((byte) 3);
      this.writeC((byte) this.Player._titles.Equiped1);
      this.writeC((byte) this.Player._titles.Equiped2);
      this.writeC((byte) this.Player._titles.Equiped3);
      this.writeQ(this.Player._titles.Flags);
      this.writeC((byte) 160);
      this.writeB(this.Player._mission.list1);
      this.writeB(this.Player._mission.list2);
      this.writeB(this.Player._mission.list3);
      this.writeB(this.Player._mission.list4);
      this.writeC((byte) this.Player._mission.actualMission);
      this.writeC((byte) this.Player._mission.card1);
      this.writeC((byte) this.Player._mission.card2);
      this.writeC((byte) this.Player._mission.card3);
      this.writeC((byte) this.Player._mission.card4);
      this.writeB(ComDiv.getCardFlags(this.Player._mission.mission1, this.Player._mission.list1));
      this.writeB(ComDiv.getCardFlags(this.Player._mission.mission2, this.Player._mission.list2));
      this.writeB(ComDiv.getCardFlags(this.Player._mission.mission3, this.Player._mission.list3));
      this.writeB(ComDiv.getCardFlags(this.Player._mission.mission4, this.Player._mission.list4));
      this.writeC((byte) this.Player._mission.mission1);
      this.writeC((byte) this.Player._mission.mission2);
      this.writeC((byte) this.Player._mission.mission3);
      this.writeC((byte) this.Player._mission.mission4);
      this.writeD(this.Player.blue_order);
      this.writeD(this.Player.medal);
      this.writeD(this.Player.insignia);
      this.writeD(this.Player.brooch);
      this.writeD(0);
      this.writeC((byte) 0);
      this.writeD(0);
      this.writeC((byte) 2);
      this.WriteDormantEvent();
      this.WriteVisitEvent(runningEvent);
      this.writeC((byte) 2);
      this.writeD(0);
      this.writeC((byte) 0);
      this.writeD(0);
      this.writeD(0);
      this.writeC((byte) 0);
      this.writeC((byte) 0);
      this.writeC((byte) 0);
      this.writeC((byte) 0);
      this.writeC((byte) 0);
      this.writeIP("127.0.0.1");
      this.writeD(uint.Parse(DateTime.Now.ToString("yyMMddHHmm")));
      if (this.Player.Characters.Count == 0)
      {
        this.writeC((byte) 0);
        this.writeC((byte) 1);
      }
      else
      {
        this.writeC((byte) this.Player.getCharacter(this.Player._equip._red).Slot);
        this.writeC((byte) this.Player.getCharacter(this.Player._equip._blue).Slot);
      }
      this.writeD(this.Player._inventory.getItem(this.Player._equip._dino)._id);
      this.writeD((uint) this.Player._inventory.getItem(this.Player._equip._dino)._objId);
      this.writeD(0);
      this.writeD(0);
      this.writeD(0);
      this.writeD(0);
      this.writeD(0);
      this.writeH((short) 0);
      this.writeC((byte) this.Player.name_color);
      this.writeD(this.Player._bonus.fakeRank);
      this.writeD(this.Player._bonus.fakeRank);
      this.writeUnicode(this.Player._bonus.fakeNick, 66);
      this.writeH((short) this.Player._bonus.sightColor);
      this.writeH((short) this.Player._bonus.muzzle);
      this.writeD(this.Player._statistic.fights);
      this.writeD(this.Player._statistic.fights_win);
      this.writeD(this.Player._statistic.fights_lost);
      this.writeD(this.Player._statistic.fights_draw);
      this.writeD(this.Player._statistic.kills_count);
      this.writeD(this.Player._statistic.headshots_count);
      this.writeD(this.Player._statistic.deaths_count);
      this.writeD(this.Player._statistic.totalfights_count);
      this.writeD(this.Player._statistic.totalkills_count);
      this.writeD(this.Player._statistic.escapes);
      this.writeD(this.Player._statistic.assist);
      this.writeD(this.Player._statistic.fights);
      this.writeD(this.Player._statistic.fights_win);
      this.writeD(this.Player._statistic.fights_lost);
      this.writeD(this.Player._statistic.fights_draw);
      this.writeD(this.Player._statistic.kills_count);
      this.writeD(this.Player._statistic.headshots_count);
      this.writeD(this.Player._statistic.deaths_count);
      this.writeD(this.Player._statistic.totalfights_count);
      this.writeD(this.Player._statistic.totalkills_count);
      this.writeD(this.Player._statistic.escapes);
      this.writeD(this.Player._statistic.assist);
      this.writeUnicode(this.Player.player_name, 66);
      this.writeD(this.Player._rank);
      this.writeD(this.Player._rank);
      this.writeD(this.Player._gp);
      this.writeD(this.Player._exp);
      this.writeD(0);
      this.writeC((byte) 0);
      this.writeD(0);
      this.writeQ(0L);
      this.writeC((byte) 0);
      this.writeC((byte) 0);
      this.writeD(this.Player._money);
      this.writeD(this.Clan._id);
      this.writeD(this.Player.clanAccess);
      this.writeQ(this.Player.Status());
      this.writeC((byte) this.Player.pc_cafe);
      this.writeC((byte) this.Player.tourneyLevel);
      this.writeUnicode(this.Clan._name, 34);
      this.writeC((byte) this.Clan._rank);
      this.writeC((byte) this.Clan.getClanUnit());
      this.writeD(this.Clan._logo);
      this.writeC((byte) this.Clan._name_color);
      this.writeC((byte) this.Clan.effect);
      this.writeC((byte) this.Player.age);
    */

    AckPacketInterface::Pack();
}

std::size_t PROTOCOL_BASE_GET_USER_INFO_ACK::GetMemoryUsage() {
    std::size_t dataLength = 7;
    return dataLength;
}