#include <Network/ServerPacket/PROTOCOL_BASE_GET_USER_INFO_ACK.hpp>
#include <boost/asio.hpp>
#include <Protocol/Acknowledge.hpp>
#include <Data/Model/Account.hpp>
#include <Utilities/Utils.hpp>

PROTOCOL_BASE_GET_USER_INFO_ACK::PROTOCOL_BASE_GET_USER_INFO_ACK(Account* pAccount)
: AckPacketInterface(eProtocolPacketAck::BASE_GET_USER_INFO_ACK, 0), m_pAccount(pAccount) {
    AckPacketInterface::Reserve(this->GetMemoryUsage());

    Write<std::uint16_t>(0);
    Write<std::uint32_t>(pAccount ? 0U : 2147483648U);
    if (!pAccount)
        return;

    Write<std::uint8_t>(pAccount->GetCharactersCount());
    Write<std::uint16_t>(210);
    Write<std::uint8_t>(0); //quickstart count
    /*
        Write<std::uint8_t>(GetQuickStart()->GetCount());
        for (auto& quickStart : GetQuickStart()->GetData()) {
            Write<std::uint8_t>(quickStart.GetMapID());
            Write<std::uint8_t>(quickStart.GetRule());
            Write<std::uint8_t>(quickStart.GetStageOptions());
            Write<std::uint8_t>(quickStart.GetType());
        }
    */ 
    MemorySet(0, 33);
    Write<std::uint8_t>(4);
    Write<std::uint32_t>(0);
    Write<std::uint32_t>(0);
    Write<std::uint32_t>(0);
    Write<std::uint32_t>(0);
    Write<std::uint32_t>(0);
    
    Write<std::uint32_t>(pAccount->GetTitle().GetAvailableSlots());
    Write<std::uint8_t>(3); //I guess.. this might be equiped titles count
    Write<std::uint8_t>(pAccount->GetTitle().GetEquiped(0));
    Write<std::uint8_t>(pAccount->GetTitle().GetEquiped(1));
    Write<std::uint8_t>(pAccount->GetTitle().GetEquiped(2));
    Write<std::uint64_t>(pAccount->GetTitle().GetFlags());
    
    Write<std::uint8_t>(160);
    /* 
    this.writeB(this.Player._mission.list1);
    this.writeB(this.Player._mission.list2);
    this.writeB(this.Player._mission.list3);
    this.writeB(this.Player._mission.list4); //160
    this.writeC((byte) this.Player._mission.actualMission);
    this.writeC((byte) this.Player._mission.card1);
    this.writeC((byte) this.Player._mission.card2);
    this.writeC((byte) this.Player._mission.card3);
    this.writeC((byte) this.Player._mission.card4);
    this.writeB(ComDiv.getCardFlags(this.Player._mission.mission1, this.Player._mission.list1));
    this.writeB(ComDiv.getCardFlags(this.Player._mission.mission2, this.Player._mission.list2));
    this.writeB(ComDiv.getCardFlags(this.Player._mission.mission3, this.Player._mission.list3));
    this.writeB(ComDiv.getCardFlags(this.Player._mission.mission4, this.Player._mission.list4)); //20
    this.writeC((byte) this.Player._mission.mission1);
    this.writeC((byte) this.Player._mission.mission2);
    this.writeC((byte) this.Player._mission.mission3);
    this.writeC((byte) this.Player._mission.mission4);
    this.writeD(this.Player.blue_order);
    this.writeD(this.Player.medal);
    this.writeD(this.Player.insignia);
    this.writeD(this.Player.brooch);
    */ //265
    MemorySet(0, 265);

    Write<std::uint32_t>(0);
    Write<std::uint8_t>(0);
    Write<std::uint32_t>(0);
    Write<std::uint8_t>(2);
    
    MemorySet(0, 375); // DormantEvent
    MemorySet(0, 375); // VisitEvent

    Write<std::uint8_t>(2);
    Write<std::uint32_t>(0);
    Write<std::uint8_t>(0);
    Write<std::uint32_t>(0);
    Write<std::uint32_t>(0);
    Write<std::uint8_t>(0);
    Write<std::uint8_t>(0);
    Write<std::uint8_t>(0);
    Write<std::uint8_t>(0);
    Write<std::uint8_t>(0);

    auto addressBytes = boost::asio::ip::address::from_string("127.0.0.1").to_v4().to_bytes();

    Write(addressBytes.data(), addressBytes.size()); //this.writeIP("127.0.0.1");
    Write<std::uint32_t>(std::stoul(GetFormatTime(system_clock::now(), "%y%m%d%H%M"))); //this.writeD(uint.Parse(DateTime.Now.ToString("yyMMddHHmm")));
    if (pAccount->GetCharactersCount() == 0) {
        Write<std::uint8_t>(0);
        Write<std::uint8_t>(1);   
    } else {
        /*
        this.writeC((byte) this.Player.getCharacter(this.Player._equip._red).Slot);
        this.writeC((byte) this.Player.getCharacter(this.Player._equip._blue).Slot);
        */
    }
    Write<std::uint32_t>(0); //this.writeD(this.Player._inventory.getItem(this.Player._equip._dino)._id);
    Write<std::uint32_t>(0); //this.writeD((uint) this.Player._inventory.getItem(this.Player._equip._dino)._objId);
    Write<std::uint32_t>(0);
    Write<std::uint32_t>(0);
    Write<std::uint32_t>(0);
    Write<std::uint32_t>(0);
    Write<std::uint32_t>(0);
    Write<std::uint16_t>(0);
    /*  
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