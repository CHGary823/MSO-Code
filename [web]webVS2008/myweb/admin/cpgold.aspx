<%@ Register TagPrefix="uc1" TagName="cptop" Src="../control/cptop.ascx" %>
<%@ Register TagPrefix="uc1" TagName="cpmenu" Src="../control/cpmenu.ascx" %>
<%@ Register TagPrefix="fckeditorv2" Namespace="FredCK.FCKeditorV2" Assembly="FredCK.FCKeditorV2" %>
<%@ Page language="c#" Codebehind="cpgold.aspx.cs" AutoEventWireup="false" Inherits="web.admin.cpgold" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>admincp</title>
		<meta content="Microsoft Visual Studio .NET 7.1" name="GENERATOR">
		<meta content="C#" name="CODE_LANGUAGE">
		<meta content="JavaScript" name="vs_defaultClientScript">
		<meta content="http://schemas.microsoft.com/intellisense/ie5" name="vs_targetSchema">
		<SCRIPT language="JavaScript" src="Common/JavaScript/Menu.js"></SCRIPT>
		<LINK href="Common/CSS/Default.CSS" type="text/css" rel="stylesheet">
		<LINK href="Common/CSS/menuStyleXP.CSS" type="text/css" rel="stylesheet">
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form id="Form1" method="post" runat="server">
			<uc1:cptop id="Cptop1" runat="server"></uc1:cptop>
			<table id="Table1" cellSpacing="1" cellPadding="3" width="780" border="0">
				<tr>
					<td vAlign="top" width="207" rowSpan="2">
						<table cellSpacing="0" cellPadding="0" width="100%" align="center" border="0">
							<tr bgColor="#bcbcbc">
								<td>
									<table cellSpacing="1" cellPadding="10" width="100%" border="0">
										<tr bgColor="#efefef">
											<td vAlign="top" height="498"><uc1:cpmenu id="Cpmenu1" runat="server"></uc1:cpmenu></td>
										</tr>
										<tr bgColor="#f9f9f9">
											<td height="80">
												<div align="center">
													<p><font color="#ff6633"><A href="../logout.aspx" target="_blank"><b><font color="#ff6666">�]�N�˳�</b></A></p>
												</div>
												</FONT></FONT></td>
										</tr>
									</table>
								</td>
							</tr>
						</table>
					</td>
					<td vAlign="top" width="556">
						<table id="Table2" cellSpacing="0" cellPadding="0" width="563" align="center" border="0">
							<tr bgColor="#bcbcbc">
								<td>
									<table id="Table3" cellSpacing="1" cellPadding="8" width="100%" border="0">
										<tr bgColor="#efefef">
											<td vAlign="top" align="left">
												<TABLE id="Table4" style="WIDTH: 560px" cellSpacing="1" cellPadding="1" width="560" border="0">
													<TR>
														<TD style="WIDTH: 107px; HEIGHT: 36px" colSpan="2"><b>����֧�����I�б�
																<asp:dropdownlist id="ddagentid" runat="server" AutoPostBack="True"></asp:dropdownlist></b></TD>
													</TR>
													<TR>
														<TD colSpan="2"><asp:datagrid id="DataGrid1" runat="server" PageSize="20" AllowPaging="True" Width="552px" AutoGenerateColumns="False">
																<Columns>
																	<asp:BoundColumn DataField="id" HeaderText="��̖"></asp:BoundColumn>
																	<asp:BoundColumn DataField="adminid" HeaderText="����T"></asp:BoundColumn>
																	<asp:BoundColumn DataField="agentid" HeaderText="����"></asp:BoundColumn>
																	<asp:BoundColumn DataField="gold" HeaderText="����"></asp:BoundColumn>
																	<asp:BoundColumn DataField="date" HeaderText="�����r�g"></asp:BoundColumn>
																</Columns>
																<PagerStyle Mode="NumericPages"></PagerStyle>
															</asp:datagrid></TD>
													</TR>
													<TR>
														<TD align="left" colSpan="2">
															<hr>
														</TD>
													</TR>
													<TR>
														<TD style="WIDTH: 55px" align="left"><B>���Űl��</B></TD>
														<TD align="left"></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 77px; HEIGHT: 13px" align="left">����ID</TD>
														<TD style="HEIGHT: 13px" align="left"><asp:dropdownlist id="ddagent" runat="server"></asp:dropdownlist>
															<asp:CheckBox id="cblog" runat="server" Text="�Ƿ�ӛ����I"></asp:CheckBox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 77px; HEIGHT: 13px" align="left">���ID</TD>
														<TD style="HEIGHT: 13px" align="left">
															<asp:textbox id="playerid" runat="server" Width="120px" Columns="10"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 77px" align="left">���Ŕ���</TD>
														<TD align="left"><asp:textbox id="tbgold" runat="server" Width="120px" Columns="10"></asp:textbox>*������ؓ������ʾ�p��</TD>
													</TR>
													<TR>
														<TD align="left" colSpan="2"><FONT face="����"></FONT></TD>
													</TR>
													<TR>
														<TD align="center" colSpan="2"><asp:button id="btnedit" runat="server" Text="��  ��"></asp:button></TD>
													</TR>
												</TABLE>
											</td>
										</tr>
									</table>
								</td>
							</tr>
						</table>
					</td>
				</tr>
			</table>
		</form>
	</body>
</HTML>
